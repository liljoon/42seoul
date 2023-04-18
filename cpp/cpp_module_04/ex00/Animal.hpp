#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(Animal &other);
	Animal &operator=(Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};


#endif
