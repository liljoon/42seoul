#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <typeinfo>

template <typename T, int N>
struct PmergeMe
{
	static void make_groups(std::vector<std::pair<T, T> > &v, const std::vector<T> &arr)
	{
		for (size_t i = 1; i < arr.size(); i += 2)
			v.push_back(std::make_pair<T, T>(arr[i - 1], arr[i]));

		for (size_t i = 0; i < v.size(); i++)
		{
			if (v[i].first < v[i].second)
				std::swap(v[i].first, v[i].second);
		}
	}

	static void sort_v(std::vector<T> &arr)
	{
		if (arr.size() <= 1)
			return;

		std::vector<std::pair<T, T> > temp;
		PmergeMe::make_groups(temp, arr);

		PmergeMe<std::pair<T, T>, N - 1 >::sort_v(temp);
		//std::sort(temp.begin(), temp.end());

		std::vector<T> main_chain;
		std::vector<T> sub_chain;
		for (size_t i = 0; i < temp.size(); i++) // 전부 하나씩 집어 넣고 시작.
		{
			main_chain.push_back(temp[i].first);
			sub_chain.push_back(temp[i].second);
		}
		if (arr.size() % 2 == 1) // odd
			sub_chain.push_back(arr[arr.size() - 1]);

		for (size_t i = 0; i < sub_chain.size(); i++)
		{
			typename std::vector<T>::iterator it_toinsert;

			int delta;
			if (arr.size() % 2 == 1 && i == sub_chain.size() - 1) // 홀수 일경우 마지막에 두개 건너 뜀
				delta = 2 *i;
			else
				delta = 2 * i + 1 ;

			it_toinsert = std::lower_bound(main_chain.begin(), main_chain.begin() + delta, sub_chain[i]);
			main_chain.insert(it_toinsert, sub_chain[i]);
		}
		arr = main_chain;
	}
};

template <typename T>
struct PmergeMe<T, 0>
{
	static void sort_v(std::vector<T> &arr)
	{
		(void)arr;
		return;
	}
};

#endif
