#include "Array.hpp"

#include <iostream>

int main()
{
	{
		Array<int> arr(10);

		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << std::endl;
		for (int i = 0; i < 10; i++)
			arr[i] = i;
		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << std::endl;
	}
	{
		Array<int> arr;

		try
		{
			std::cout << arr[11] << std::endl;
		}
		catch (const std::out_of_range &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	// system("leaks a.out");
}
