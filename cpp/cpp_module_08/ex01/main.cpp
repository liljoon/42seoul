#include "Span.hpp"
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>


int main()
{
	std::vector<int> test_v;
	std::list<int> test_li;

	std::srand(std::time(0));
	for(int i = 0; i < 20000; i++)
	{
		int temp = rand() % 1000000 + 1 ;
		test_v.push_back(temp);
		test_li.push_back(temp);
	}

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
		Span sp = Span(20001);

		sp.addNumber(100);


		sp.addByIterator(test_v.begin(), test_v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(20001);

		sp.addNumber(100);

		sp.addByIterator(test_li.begin(), test_li.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	//error
	{
		try
		{
			Span sp(0);

			sp.addNumber(10);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Span sp(2);

			sp.addNumber(10);
			sp.addNumber(10);
			sp.addNumber(10);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Span sp(2);

			sp.addNumber(10);
			std::cout << sp.shortestSpan() << std::endl;
			//std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Span sp(2);

			sp.addNumber(10);
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Span sp(10);
			std::vector<int> v(10, 321);

			sp.addNumber(123);
			sp.addByIterator(v.begin(), v.end());
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}
