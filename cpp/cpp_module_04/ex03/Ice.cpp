#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

AMateria *Ice::clone() const
{
    Ice *ret = new Ice(*this);

    return ret;
}
