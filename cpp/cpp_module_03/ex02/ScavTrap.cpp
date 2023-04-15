#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap : " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap : " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap : " << name << " created!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : " << name << " deleted!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ScavTrap " << name << " Can't do anything!" << std::endl;
	else
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage
				  << " points of damage!"
				  << std::endl;
	}
	std::cout << "energyPoints : " << energyPoints << " hitPoints : " << hitPoints << std::endl << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap : " << name << " is now in Gate keeper mode!" << std::endl;
}
