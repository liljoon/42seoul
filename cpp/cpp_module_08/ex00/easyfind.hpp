#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &con, const int &target)
{
	typename T::iterator it;
	it = std::find(con.begin(), con.end(), target);

	if (it == con.end())
		throw std::invalid_argument("no occurrence");
	else
		return it;
}

#endif
