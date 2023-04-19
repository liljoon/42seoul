#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << type << " : Default Constructor!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << type << " : Destructor!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << type << " : Meow!" << std::endl;
}