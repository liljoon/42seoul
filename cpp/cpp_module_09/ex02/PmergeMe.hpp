#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <vector>

template <typename T>
void PmergeMe(std::vector<T> &arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<std::pair<T, T> > temp;
	for (size_t i = 0; i < arr.size(); i+=2)
		temp.push_back(std::make_pair<T, T>(arr[i], arr[i + 1]));
	// 홀수일 때 추가하기...

	for (size_t i = 0; i < temp.size(); i++)
	{
		if (temp[i].first < temp[i].second)
			std::swap(temp[i].first, temp[i].second);
	}

	std::sort(temp.begin(), temp.end()); // 추후 recursive 로 변환

	// for (size_t i = 0; i < temp.size(); i++)
	// {
	// 	std::cout<< temp[i].first << " "<<temp[i].second << std::endl;
	// }
	std::vector<T> sorted_temp;
	for(size_t i = 0;i < sorted_temp.size(); i++)
		sorted_temp.push_back(temp[i].first);


}

#endif
