#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	Dog *d = new Dog();
	Dog *k = new Dog(*d);

	delete d;
	delete k;
	delete j;//should not create a leak
	delete i;
	return 0;
}