#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->top = 0;
	for (int i = 0; i < 8; i++)
		data[i].set_idx(-1);
}

int my_getline(std::string &cmd)
{
	std::getline(std::cin, cmd);
	if (std::cin.eof())
		exit(0);
	if (cmd.length() == 0)
		return 1;
	for (int i = 0; i < (int)cmd.length(); i++)
	{
		if (std::isspace(cmd[i]))
			return 1;
	}
	return 0;
}

void PhoneBook::loop_start()
{
	std::string command;
	while (1)
	{
		std::cout << "command : ";
		my_getline(command);
		if (command == "ADD")
			add_process();
		else if (command == "SEARCH")
			search_process();
		else if (command == "EXIT")
			break;
	}
}

void PhoneBook::add_process()
{
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;
	std::cout << "first name : ";
	if (my_getline(first_name))
	{
		std::cout << "Empty!" << std::endl;
		return;
	}
	// 예외처리, 비어있거나 ,eof
	std::cout << "last name : ";
	if (my_getline(last_name))
	{
		std::cout << "Empty!" << std::endl;
		return;
	}
	std::cout << "nick name : ";
	if (my_getline(nick_name))
	{
		std::cout << "Empty!" << std::endl;
		return;
	}
	std::cout << "phone number : ";
	if (my_getline(phone_number))
	{
		std::cout << "Empty!" << std::endl;
		return;
	}
	std::cout << "darkest secret : ";
	if (my_getline(darkest_secret))
	{
		std::cout << "Empty!" << std::endl;
		return;
	}

	data[top] = Contact(top, first_name, last_name, nick_name, phone_number, darkest_secret);
	top = (top + 1) % 8;
}

void print_only_10(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << std::setw(10) << str.substr(0, 9) + ".";
}

void PhoneBook::print_all_contacts()
{
	print_only_10("index");
	std::cout << '|';
	print_only_10("first name");
	std::cout << '|';
	print_only_10("last name");
	std::cout << '|';
	print_only_10("nick name");
	std::cout << std::endl;

	for (int i = 0; i < 8; i++)
	{
		Contact ct = data[i];

		if (ct.get_idx() == -1)
			continue;
		print_only_10(std::to_string(ct.get_idx() + 1));
		std::cout << '|';
		print_only_10(ct.get_first_name());
		std::cout << '|';
		print_only_10(ct.get_last_name());
		std::cout << '|';
		print_only_10(ct.get_nick_name());
		std::cout << std::endl;
	}
}

void PhoneBook::search_process()
{
	std::string input;
	int idx;

	print_all_contacts();
	std::cout << "Find index : ";
	my_getline(input);
	idx = std::atoi(input.c_str());
	if (idx <= 0 || idx >= 8)
	{
		std::cout << "Wrong Input" << std::endl;
		return;
	}
	print_contact(idx - 1);
}

void PhoneBook::print_contact(int data_idx)
{
	Contact ct = data[data_idx];

	if (ct.get_idx() == -1)
	{
		std::cout << "No Data" << std::endl;
		return;
	}
	std::cout << "index : " << ct.get_idx() + 1 << std::endl;
	std::cout << "first name : " << ct.get_first_name() << std::endl;
	std::cout << "last name : " << ct.get_last_name() << std::endl;
	std::cout << "nick name : " << ct.get_nick_name() << std::endl;
	std::cout << "phone number : " << ct.get_phone_number() << std::endl;
	std::cout << "darkest secret : " << ct.get_darkest_secret() << std::endl;
}
