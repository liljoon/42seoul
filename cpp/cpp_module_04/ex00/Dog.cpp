#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << type << " : Default Constructor!" << std::endl;
}

Dog::Dog(Dog &other)
{
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

Dog &Dog::operator=(Dog &other)
{
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);

}

Dog::~Dog()
{
	std::cout << type << " : Destructor!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << " : Bark!" << std::endl;
}
