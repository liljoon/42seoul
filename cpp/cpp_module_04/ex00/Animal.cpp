#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << type << " : Default Constructor!" << std::endl;
}

Animal::Animal(Animal &other)
{
	std::cout << type << " : Copy Constructor!" << std::endl;
	this->type = other.type;
}

Animal &Animal::operator=(Animal &other)
{
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	this->type = other.type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << type << " : Destructor!" << std::endl;
}

void Animal::makeSound() const
{
}

std::string Animal::getType() const
{
	return (this->type);
}
