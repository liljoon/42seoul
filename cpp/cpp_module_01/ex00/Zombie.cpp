#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("default")
{
}

Zombie::Zombie(std::string name) : name(name)
{
}

Zombie::~Zombie()
{
	std::cout << this->name << " destroyed!" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
