#include "Cure.hpp"

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
