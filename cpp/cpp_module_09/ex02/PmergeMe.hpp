#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <utility>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>

template <typename li_T>
static li_T &getIndex_li(std::list<li_T> &li, size_t index)
{
	typename std::list<li_T>::iterator it = li.begin();
	std::advance(it, index);

	return (*it);
}

template <typename T, int N>
class PmergeMe
{
private:
	PmergeMe() {};
	PmergeMe(const PmergeMe &other) {(void)other;};
	PmergeMe &operator=(const PmergeMe &other) {(void)other;};
	~PmergeMe() {};

	static std::vector<std::pair<T, T> > groups;
	static std::vector<T> main_chain;
	static std::vector<T> sub_chain;

	static std::list<std::pair<T, T> > groups_li;
	static std::list<T> main_chain_li;
	static std::list<T> sub_chain_li;



	static void putChain(int left, int right)
	{
		right--;
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

	static void putChain_li(int left, int right)
	{
		right--;
		int delta = -1;
		for (int i = left; i <= right; i++)
		{
			if (i >= static_cast<int>(groups_li.size()))
			{
				delta = 0;
				break;
			}
			main_chain_li.push_back(getIndex_li(groups_li, i).first);
		}

		while (left <= right)
		{
			typename std::list<T>::iterator it_toinsert;
			typename std::list<T>::iterator it_delta = main_chain_li.end();

			if (delta == -1)
				it_delta--;
			it_toinsert = std::lower_bound(main_chain_li.begin(), it_delta, getIndex_li(sub_chain_li, right));
			main_chain_li.insert(it_toinsert, getIndex_li(sub_chain_li, right));
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

	static std::list<int> makeJacobsthalNumber_li()
	{
		std::list<int> ret;
		int sub_chain_size = sub_chain_li.size();

		int temp = 1;
		while (temp <= sub_chain_size)
		{
			ret.push_back(temp);
			temp = static_cast<int>(std::pow(2, ret.size() + 1) - temp);
		}
		if (getIndex_li(ret, ret.size() - 1) != sub_chain_size)
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

	static void make_groups_li(std::list<T> &arr)
	{
		for (size_t i = 1; i < arr.size(); i += 2)
			groups_li.push_back(std::make_pair<T, T>(getIndex_li(arr, i - 1), getIndex_li(arr, i)));

		for (size_t i = 0; i < groups_li.size(); i++)
		{
			if (getIndex_li(groups_li, i).first < getIndex_li(groups_li, i).second)
				std::swap(getIndex_li(groups_li, i).first, getIndex_li(groups_li, i).second);
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

		std::vector<int> JacobsthalNumber = makeJacobsthalNumber();
		JacobsthalNumber.insert(JacobsthalNumber.begin(), 0);

		for (size_t i = 0; i < JacobsthalNumber.size() - 1; i++)
		{
			PmergeMe::putChain(JacobsthalNumber[i], JacobsthalNumber[i + 1]);
		}
		arr = main_chain;
	}

	static void sort_li(std::list<T> &arr)
	{
		if (arr.size() <= 1)
			return;

		PmergeMe::make_groups_li(arr);

		PmergeMe<std::pair<T, T>, N - 1>::sort_li(groups_li);

		for (size_t i = 0; i < groups_li.size(); i++)
			sub_chain_li.push_back(getIndex_li(groups_li, i).second);

		if (arr.size() % 2 == 1) // odd
			sub_chain_li.push_back(getIndex_li(arr, arr.size() - 1));

		std::list<int> JacobsthalNumber = makeJacobsthalNumber_li();
		JacobsthalNumber.insert(JacobsthalNumber.begin(), 0);

		for (size_t i = 0; i < JacobsthalNumber.size() - 1; i++)
		{
			PmergeMe::putChain_li(getIndex_li(JacobsthalNumber, i), getIndex_li(JacobsthalNumber, i + 1));
		}
		arr = main_chain_li;
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

	static void sort_li(std::list<T> &arr)
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

template <typename T, int N>
std::list<std::pair<T, T> > PmergeMe<T, N>::groups_li = std::list<std::pair<T, T> >();

template <typename T, int N>
std::list<T> PmergeMe<T, N>::main_chain_li = std::list<T>();

template <typename T, int N>
std::list<T> PmergeMe<T, N>::sub_chain_li = std::list<T>();

template <typename Container>
bool check_error(const Container &con)
{
	typename Container::const_iterator it = con.begin();

	while (it != con.end())
	{
		if (*it <= 0)
			return false;
		it++;
	}
	return true;
}


#endif
