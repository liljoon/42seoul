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

void Harl::complain(std::string level)
{
    int idx;
    void (Harl::*func_ptr[4])(void) = {&Harl::debug,
                                       &Harl::info,
                                       &Harl::warning,
                                       &Harl::error};
    std::string cmd_str[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (idx = 0; idx < 4; idx++) {
        if (level == cmd_str[idx])
            break;
    }

	switch (idx)
	{
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case 0:
		(this->*func_ptr[0])();
	case 1:
		(this->*func_ptr[1])();
	case 2:
		(this->*func_ptr[2])();
	case 3:
		(this->*func_ptr[3])();
	}
	return;
}
