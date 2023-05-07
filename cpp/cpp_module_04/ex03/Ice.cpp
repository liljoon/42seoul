#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
	(void)other;
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return *this;
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
	Ice *ret = new Ice(*this);

	return ret;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
