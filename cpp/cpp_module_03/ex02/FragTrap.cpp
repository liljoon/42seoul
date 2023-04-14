#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap()
{
	std::cout << "FragTrap : " << name << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap : " << name << " created!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap : " << name << " deleted!" << std::endl;
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap : " << name << " created!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap :  " << name << "High Fives!!" << std::endl;
}