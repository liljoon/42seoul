#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
protected:
public:
    Cure();
    Cure(std::string const types);
    Cure(const Cure &other);
    Cure &operator=(const Cure &other);
    ~Cure();

    // Cure &clone();
};

#endif