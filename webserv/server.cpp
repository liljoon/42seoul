#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/event.h>
#include <sys/types.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#define SERVER_IP 0x00000000
#define SERVER_PORT 80

int main()
{
	int sockFd = socket(PF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddr, client_addr;

	bzero(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = PF_INET;
	serverAddr.sin_addr.s_addr = htonl(SERVER_IP);
	serverAddr.sin_port = htons(SERVER_PORT);

	bind(sockFd, (sockaddr *)&serverAddr, sizeof(serverAddr));
	listen(sockFd, 5);


	int kq = kqueue();
	struct kevent event;
	struct kevent tevent[25];

	EV_SET(&event, sockFd, EVFILT_READ, EV_ADD | EV_CLEAR, NOTE_WRITE, 0, NULL);
	int ret = kevent(kq, &event, 1, NULL, 0, NULL);
	while (true)
	{
		ret = kevent(kq, NULL, 0, tevent, 1, NULL);
		for (int i=0;i< ret;i++)
		{
			if ((int)tevent[i].ident == sockFd)
			{
				int client_addr_size;
				client_addr_size = sizeof(client_addr);

				int newFd = accept(sockFd, (sockaddr *)&client_addr, (socklen_t *)&client_addr_size);
				EV_SET(&event, newFd, EVFILT_READ, EV_ADD | EV_CLEAR, NOTE_WRITE, 0, NULL);
				kevent(kq, &event, 1, NULL, 0, NULL);
			}
			else
			{
				char data[1024];
				read(tevent[i].ident, data, 1024);
				string s = data;
				cout << s << endl;
				ifstream fin;
				fin.open("./html/test.html");
				if (fin.fail())
					cout<<"error"<<endl;
				string line;
				while (!fin.eof())
				{
					cout<<"er";
					getline(fin, line);
					if (fin.eof())
						break;
					write(tevent[i].ident, line.c_str(), line.size());
				}
			}
		}
	}

}
