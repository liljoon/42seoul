#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template <typename Container>
typename Container::iterator easyfind(Container &con, const int &target)
{
	typename Container::iterator it;
	it = std::find(con.begin(), con.end(), target);

	if (it == con.end())
		throw std::invalid_argument("no occurrence");
	else
		return it;
}

#endif
