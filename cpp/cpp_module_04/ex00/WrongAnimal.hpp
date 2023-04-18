#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(WrongAnimal &other);
	WrongAnimal &operator=(WrongAnimal &other);
	~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
};


#endif
