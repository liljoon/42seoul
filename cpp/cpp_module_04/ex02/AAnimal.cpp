#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "Animal : Default Constructor!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "Animal : Copy Constructor!" << std::endl;
	this->type = other.type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Animal : Copy Assignment Operator!" << std::endl;
	this->type = other.type;

	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal : Destructor!" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}
