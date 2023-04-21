#include "Cat.hpp"

#include <iostream>

Cat::Cat()
{
	pBrain = new Brain();
	type = "Cat";
	std::cout << type << " : Default Constructor!" << std::endl;
}

Cat::Cat(const Cat &other)
{
	pBrain = new Brain(*(other.pBrain));
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	*pBrain = *(other.pBrain);
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete pBrain;
	std::cout << type << " : Destructor!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << type << " : Meow!" << std::endl;
}