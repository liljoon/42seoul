#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << type << " : Default Constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << type << " : Copy Constructor!" << std::endl;
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	this->type = other.type;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << type << " : Destructor!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << type << " : WrongAnimal's Sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
