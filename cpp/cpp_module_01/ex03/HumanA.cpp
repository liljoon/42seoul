#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &wp) : name(name), wp(&wp)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
