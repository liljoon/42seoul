#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cmath>

template <typename T, int N>
struct PmergeMe
{
	static void putChain(const int &left, int right, std::vector<T> &main_chain, const std::vector<T> &sub_chain, const std::vector<std::pair<T, T> > groups)
	{
		int delta = -1;
		for (int i = left; i <= right; i++)
		{
			if (i >= static_cast<int>(groups.size()))
			{
				delta = 0;
				break;
			}
			main_chain.push_back(groups[i].first);
		}

		while (left <= right)
		{
			typename std::vector<T>::iterator it_toinsert;

			it_toinsert = std::lower_bound(main_chain.begin(), main_chain.end() + delta, sub_chain[right]);
			main_chain.insert(it_toinsert, sub_chain[right]);
			right--;
		}
	}


	static std::vector<int> makeJacobsthalNumber(int sub_chain_size)
	{
		std::vector<int> ret;

		int temp = 1;
		while (temp <= sub_chain_size)
		{
			ret.push_back(temp);
			temp = static_cast<int>(std::pow(2, ret.size() + 1) - temp);
		}
		if (ret[ret.size() - 1] != sub_chain_size)
			ret.push_back(sub_chain_size);
		return ret;
	}

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

	static void sort(std::vector<T> &arr)
	{
		if (arr.size() <= 1)
			return;

		std::vector<std::pair<T, T> > temp;
		PmergeMe::make_groups(temp, arr);

		PmergeMe<std::pair<T, T>, N - 1 >::sort(temp);
		//std::sort(temp.begin(), temp.end());

		std::vector<T> main_chain;
		std::vector<T> sub_chain;
		for (size_t i = 0; i < temp.size(); i++) // 전부 하나씩 집어 넣고 시작.
		{
			//main_chain.push_back(temp[i].first);
			sub_chain.push_back(temp[i].second);
		}
		if (arr.size() % 2 == 1) // odd
			sub_chain.push_back(arr[arr.size() - 1]);

		for (size_t i = 0; i < sub_chain.size(); i++)
		{
			PmergeMe::putChain(i,i, main_chain, sub_chain, temp);
		}
		arr = main_chain;
	}
};

template <typename T>
struct PmergeMe<T, 0>
{
	static void sort(std::vector<T> &arr)
	{
		(void)arr;
		return;
	}
};

#endif
