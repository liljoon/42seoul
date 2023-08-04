#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <typeinfo>

template <typename T, int N>
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

	//std::sort(temp.begin(), temp.end());
	PmergeMe<std::pair<T, T>, N - 1 >(temp); // 추후 recursive 로 변환

	// for (size_t i = 0; i < temp.size(); i++)
	// {
	// 	std::cout<< temp[i].first << " "<<temp[i].second << std::endl;
	// }
	std::vector<T> sorted_temp;
	for(size_t i = 0;i < temp.size(); i++) // 하나씩 넣고 하나씩 앞에 추가.
	{
		sorted_temp.push_back(temp[i].first);

		typename std::vector<T>::iterator it_toinsert;
		it_toinsert = std::lower_bound(sorted_temp.begin(), sorted_temp.end(), temp[i].second);
		sorted_temp.insert(it_toinsert, temp[i].second);
	}
	arr = sorted_temp;
}

// template <typename T, 0>
// void PmergeMe(T &arr)
// {
// 	(void)arr;
// 	return ;
// }

#endif
