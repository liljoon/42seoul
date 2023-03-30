#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->top = 0;
}

void PhoneBook::loop_start()
{
	std::string command;
	while (1)
	{
		std::cout << "command : ";
		std::cin >> command;
		if (command == "ADD")
			add_process();
		else if (command == "SEARCH")
		{
		}
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
