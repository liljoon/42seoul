#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat : Default Constructor!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	this->type = other.type;
	std::cout << "Cat : Copy Constructor!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	this->type = other.type;
	std::cout << "Cat: Copy Assignment Operator!" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat : Destructor!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Cat : Meow!" << std::endl;
}