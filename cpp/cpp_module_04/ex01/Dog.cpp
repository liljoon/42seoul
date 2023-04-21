#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	pBrain = new Brain();
	type = "Dog";
	std::cout << type << " : Default Constructor!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	pBrain = new Brain(*(other.pBrain));
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	*pBrain = *(other.pBrain);
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete pBrain;
	std::cout << type << " : Destructor!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << type << " : Bark!" << std::endl;
}