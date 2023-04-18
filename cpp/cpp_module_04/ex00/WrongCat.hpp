#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:

public:
	WrongCat();
	WrongCat(WrongCat &other);
	WrongCat &operator=(WrongCat &other);
	~WrongCat();
	void makeSound() const;
};


#endif
