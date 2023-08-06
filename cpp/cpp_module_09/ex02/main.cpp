#include "PmergeMe.hpp"
#include <vector>
#include <cstdlib>
#include <random>
#include <sys/time.h>

void print_time(int len, timespec ts1, timespec ts2, std::string con_type)
{
	long nanotime = ts2.tv_nsec - ts1.tv_nsec;
	double ustime = nanotime / 1000.0;

	std::cout << "Time to process a range of " << len << " elements with std::" << con_type << " : " << ustime << " us" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	std::vector<int> v;
	std::list<int> li;
	timespec ts1, ts2;

	srand(time(0));

	for (int i = 1; i < argc; i++)
	{
		v.push_back(std::atoi(argv[i]));
		li.push_back(std::atoi(argv[i]));
	}

	if (!check_error(v))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	std::cout << "Before :\t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	clock_gettime(CLOCK_REALTIME, &ts1);
	PmergeMe<int, 15>::sort(v);
	clock_gettime(CLOCK_REALTIME, &ts2);
	std::cout << "After : \t";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	print_time(v.size(), ts1, ts2, "vector");

	clock_gettime(CLOCK_REALTIME, &ts1);
	PmergeMe<int, 15>::sort_li(li);
	clock_gettime(CLOCK_REALTIME, &ts2);
	print_time(v.size(), ts1, ts2, "list");
}
