#include "Cure.hpp"
#include <iostream>

Cure::Cure(const Cure &other)
{
	this->type = other.type;
}

Cure::Cure() : AMateria("cure")
{
}

Cure &Cure::operator=(const Cure &other)
{
	this->type = other.type;

	return *this;
}

AMateria *Cure::clone() const
{
	Cure *ret = new Cure(*this);

	return ret;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
