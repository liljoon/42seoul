#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat : Default Constructor!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "WrongCat : Copy Constructor!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	this->type = other.type;
	std::cout << "WrongCat: Copy Assignment Operator!" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat : Destructor!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat : Meow!" << std::endl;
}