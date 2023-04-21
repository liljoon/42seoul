#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	brain = new Brain();
	type = "Dog";
	std::cout << type << " : Default Constructor!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	brain = new Brain(*(other.brain));
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	*brain = *(other.brain);
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << type << " : Destructor!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << " : Bark!" << std::endl;
}