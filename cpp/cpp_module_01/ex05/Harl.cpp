#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

unsigned long djb2_hash(std::string str)
{
	unsigned long hash = 5381;

	for (int i = 0; i < str.size(); i++)
		hash = ((hash << 5) + hash) + str[i];
	return hash;
}

void Harl::complain(std::string level)
{
	int idx;
	void (Harl::*func_ptr[4])(void);

	func_ptr[0] = &Harl::debug;
	func_ptr[1] = &Harl::info;
	func_ptr[2] = &Harl::warning;
	func_ptr[3] = &Harl::error;

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
