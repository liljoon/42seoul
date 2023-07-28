#include "Span.hpp"
#include <iostream>
#include <list>

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(6);

		sp.addNumber(100);

		std::vector<int> v(5);
		v[0] = (6);
		v[1] = (3);
		v[2] = (17);
		v[3] = (9);
		v[4] = (11);

		sp.addByIterator(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(6);

		sp.addNumber(100);

		std::list<int> li;
		li.push_back(6);
		li.push_back(3);
		li.push_back(17);
		li.push_back(9);
		li.push_back(11);

		sp.addByIterator(li.begin(), li.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}
