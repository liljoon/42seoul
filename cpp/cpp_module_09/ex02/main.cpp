#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>
#include <random>

int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;

	std::vector<int> v;
	srand(time(0));

	for (int i = 1; i < argc; i++)
		v.push_back(std::atoi(argv[i]));

	if (!check_error(v))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::cout << "Before :\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	PmergeMe<int, 15>::sort(v);

	std::cout << "After : \t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}
