#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
protected:
public:
    Ice();
    Ice(std::string type);
    Ice(const Ice &other);
    Ice &operator=(const Ice &other);
    ~Ice();

    // Ice clone();
};

#endif