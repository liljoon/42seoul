#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "WrongAnimal : Default Constructor!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal : Copy Constructor!" << std::endl;
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal : Copy Assignment Operator!" << std::endl;
	this->type = other.type;

	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal : Destructor!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal : WrongAnimal's Sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
