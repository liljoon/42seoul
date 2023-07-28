#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(0));
	std::vector<int> v;
	// std::deque<int> v;
	// std::list<int> v;

	for (int i = 0; i < 10; i++)
	{
		int temp = rand() % 100;
		v.push_back(temp);
		std::cout << temp << " ";
	}
	std::cout << std::endl;
	int input = 0;
	while (input != -1)
	{
		std::cin >> input;
		try
		{
			std::cout << easyfind(v, input) - v.begin() << std::endl;
			// std::cout << *easyfind(v, input) << std::endl; // list
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
