#include "iter.hpp"
#include <iostream>

template <typename T>
void print_arr(T i)
{
	std::cout << i << std::endl;
}

int main()
{
	const int len = 10;

	// int arr[len];
	char arr[len];
	for (int i = 0; i < len; i++)
		arr[i] = i + 97;

	iter(arr, len, print_arr);
}
