#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <cmath>



template <typename T, int N>
class PmergeMe
{
private:
	static std::vector<std::pair<T, T> > groups;
	static std::vector<T> main_chain;
	static std::vector<T> sub_chain;

	static void putChain(const int &left, int right)
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

	static std::vector<int> makeJacobsthalNumber()
	{
		std::vector<int> ret;
		int sub_chain_size = sub_chain.size();

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

	static void make_groups(const std::vector<T> &arr)
	{
		for (size_t i = 1; i < arr.size(); i += 2)
			groups.push_back(std::make_pair<T, T>(arr[i - 1], arr[i]));

		for (size_t i = 0; i < groups.size(); i++)
		{
			if (groups[i].first < groups[i].second)
				std::swap(groups[i].first, groups[i].second);
		}
	}

public:
	static void sort(std::vector<T> &arr)
	{
		if (arr.size() <= 1)
			return;

		PmergeMe::make_groups(arr);

		PmergeMe<std::pair<T, T>, N - 1 >::sort(groups);

		for (size_t i = 0; i < groups.size(); i++)
			sub_chain.push_back(groups[i].second);

		if (arr.size() % 2 == 1) // odd
			sub_chain.push_back(arr[arr.size() - 1]);

		for (size_t i = 0; i < sub_chain.size(); i++)
		{
			PmergeMe::putChain(i,i);
		}
		arr = main_chain;
	}
};

template <typename T>
class PmergeMe<T, 0>
{
public:
	static void sort(std::vector<T> &arr)
	{
		(void)arr;
		return;
	}
};

template <typename T, int N>
std::vector<std::pair<T, T> > PmergeMe<T, N>::groups = std::vector<std::pair<T, T> >();

template <typename T, int N>
std::vector<T> PmergeMe<T, N>::main_chain = std::vector<T>();

template <typename T, int N>
std::vector<T> PmergeMe<T, N>::sub_chain = std::vector<T>();

#endif
