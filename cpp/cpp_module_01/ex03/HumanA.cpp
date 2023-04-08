#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &wp) : wp(&wp), name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
