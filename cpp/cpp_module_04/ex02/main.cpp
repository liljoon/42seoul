#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j; // should not create a leak
	delete i;

	// const int N = 10;
	// Animal *arr[N];

	// for (int i = 0; i < N / 2; i++)
	// 	arr[i] = new Dog();
	// for (int i = N / 2; i < N; i++)
	// 	arr[i] = new Cat();
	// for (int i = 0; i < N; i++)
	// 	arr[i]->makeSound();

	// for (int i = 0; i < N; i++)
	// 	delete arr[i];

	// Dog *d1 = new Dog();
	// Dog *d2 = new Dog(*d1);
	// Cat *c1 = new Cat();
	// Cat *c2 = new Cat();
	// *c2 = *c1;

	// delete d1;
	// delete d2;
	// delete c1;
	// delete c2;

	return 0;
}