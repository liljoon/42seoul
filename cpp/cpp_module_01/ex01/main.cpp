#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *zom_arr = zombieHorde(N, "Foo");
	for (int i = 0; i < N; i++)
		zom_arr[i].announce();

	delete[] zom_arr;
	return (0);
}
