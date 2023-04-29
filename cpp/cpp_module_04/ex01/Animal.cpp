#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
	std::cout << "Animal : Default Constructor!" << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal : Copy Constructor!" << std::endl;
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Copy Assignment Operator!" << std::endl;
	this->type = other.type;

	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal : Destructor!" << std::endl;
}

void Animal::makeSound() const
{
}

std::string Animal::getType() const
{
	return (this->type);
}
