#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap : " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	std::cout << "ClapTrap : " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : " << name << " deleted!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ClapTrap " << name << " Can't do anything!" << std::endl;
	else
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage
				  << " points of damage!"
				  << std::endl;
	}
	std::cout << "energyPoints : " << energyPoints << " hitPoints : " << hitPoints << std::endl << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->hitPoints -= amount;
	if (this->hitPoints < 0)
		this->hitPoints = 0;
	std::cout << "ClapTrap " << name << " took " << amount << " points of damage!"
			  << std::endl;
	std::cout << "energyPoints : " << energyPoints << " hitPoints : " << hitPoints << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0 || energyPoints == 0)
		std::cout << "ClapTrap " << name << " Can't do anything!" << std::endl;
	else
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired " << amount << " points!!" << std::endl;
	}
	std::cout << "energyPoints : " << energyPoints << " hitPoints : " << hitPoints << std::endl << std::endl;
}