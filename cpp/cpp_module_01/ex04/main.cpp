#include <iostream>
#include <fstream>
#include <string>

void replace_str(std::string &str, std::string before, std::string after)
{
	size_t idx = 0;

	while (idx < str.length())
	{
		idx = str.find(before, idx);
		if (idx == str.npos)
			break;
		str.erase(idx, before.length());
		str.insert(idx, after);
		idx += after.length();
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

	int length;
	infile.seekg(0, infile.end);
	length = infile.tellg();
	char *buf = new char[length + 1];
	infile.seekg(0, infile.beg);
	infile.read(buf, length);
	buf[length] = 0;
	std::string str_buf = buf;
	replace_str(str_buf, str1, str2);
	outfile << str_buf;
	infile.close();
	outfile.close();

	delete[] buf;
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
