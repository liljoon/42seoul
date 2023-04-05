#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &wp)
{
	this->wp = &wp;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
}
