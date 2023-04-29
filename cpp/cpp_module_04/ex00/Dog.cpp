#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog : Default Constructor!" << std::endl;
}

Dog::Dog(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog : Copy Constructor!" << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	this->type = other.type;
	std::cout << "Dog: Copy Assignment Operator!" << std::endl;
	return (*this);

}

Dog::~Dog()
{
	std::cout << "Dog : Destructor!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Dog : Bark!" << std::endl;
}
