#include "PmergeMe.hpp"
#include <vector>
#include <random>

int main()
{
	std::vector<int> v;
	srand(time(0));

	for(int i=0;i<40000;i++)
		v.push_back(rand()% 100000 + 1);

	PmergeMe<int, 10>::sort(v);

	for(size_t i = 0;i < v.size();i++)
		std::cout << v[i] << std::endl;
}
