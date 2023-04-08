#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl
			  << std::endl;
}

unsigned long djb2_hash(std::string str)
{
	unsigned long hash = 5381;

	for (unsigned int i = 0; i < str.size(); i++)
		hash = ((hash << 5) + hash) + str[i];
	return hash;
}

void Harl::complain(std::string level)
{
	void (Harl::*func_ptr[4])(void) = {&Harl::debug,
									   &Harl::info,
									   &Harl::warning,
									   &Harl::error};

	switch (djb2_hash(level))
	{
	case 210670746764:
		(this->*func_ptr[0])();
		break;
	case 6384151633:
		(this->*func_ptr[1])();
		break;
	case 229444843303835:
		(this->*func_ptr[2])();
		break;
	case 210672417103:
		(this->*func_ptr[3])();
		break;
	}
	return;
}
