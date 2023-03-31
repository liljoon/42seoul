#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->top = 1;
	for (int i = 0; i < 8; i++)
		data[i].set_idx(-1);
}

void PhoneBook::loop_start()
{
	std::string command;
	while (1)
	{
		std::cout << "command : ";
		if (!(std::cin >> command))
			break;
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
	std::cin >> first_name;
	std::cout << "last name : ";
	std::cin >> last_name;
	std::cout << "nick name : ";
	std::cin >> nick_name;
	std::cout << "phone number : ";
	std::cin >> phone_number;
	std::cout << "darkest secret : ";
	std::cin >> darkest_secret;

	data[top % 8] = Contact(top, first_name, last_name, nick_name, phone_number, darkest_secret);
	top++;
}

void PhoneBook::search_process()
{
	std::string input;
	int idx, data_idx;

	std::cout << "Index : ";
	std::cin >> input;
	idx = std::atoi(input.c_str());
	if (idx <= 0)
	{
		std::cout << "Wrong Input" << std::endl;
		return;
	}
	data_idx = find_data(idx);
	if (data_idx == -1)
	{
		std::cout << "No Index!" << std::endl;
		return;
	}
	print_contact(data_idx);
}

int PhoneBook::find_data(int idx)
{
	for (int i = 0; i < 8; i++)
	{
		if (data[i].get_idx() == idx)
			return i;
	}
	return -1;
}

void print_only_10(std::string str)
{
	if (str.length() <= 10)
		std::cout << std::setw(10) << str;
	else
		std::cout << std::setw(10) << str.substr(0, 9) + ".";
}

void PhoneBook::print_contact(int data_idx)
{
	Contact ct = data[data_idx];

	print_only_10(std::to_string(ct.get_idx()));
	std::cout << '|';
	print_only_10(ct.get_first_name());
	std::cout << '|';
	print_only_10(ct.get_last_name());
	std::cout << '|';
	print_only_10(ct.get_nick_name());
	std::cout << std::endl;
}
