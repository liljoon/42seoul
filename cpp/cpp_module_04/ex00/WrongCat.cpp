#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << type << " : Default Constructor!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << type << " : Copy Constructor!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	std::cout << type << ": Copy Assignment Operator!" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << type << " : Destructor!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << type << " : Meow!" << std::endl;
}