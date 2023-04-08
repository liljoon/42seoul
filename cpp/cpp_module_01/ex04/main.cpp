#include <iostream>
#include <fstream>
#include <string>

void replace_str(std::string &str, std::string before, std::string after)
{
	unsigned int idx = 0;
	while (idx < str.size())
	{
		idx = str.find(before, idx);
		if (idx == str.npos)
			break;
		str.erase(idx, before.size());
		str.insert(idx, after);
		idx += after.size();
	}
	return;
}

void copy_file(std::string filename, std::string str1, std::string str2)
{
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile.is_open())
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	std::string buf;
	infile.seekg(0, infile.end);
	buf.resize(infile.tellg());
	infile.seekg(0, infile.beg);
	infile.read(&buf[0], buf.size());
	replace_str(buf, str1, str2);
	outfile << buf;
	infile.close();
	outfile.close();
	return;
}

int main(int argc, char *argv[])
{
	if (argc != 4 || argv[2][0] == '\0')
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	copy_file(argv[1], argv[2], argv[3]);
	return 0;
}
