#include "Zombie.hpp"

int main()
{
	Zombie *a = newZombie("Foo");
	a->announce();
	randomChump("Boo");
	delete a;

	return 0;
}
