#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"


int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737); //[...] mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;

	MutantStack<int>::reverse_iterator it_r = mstack.rbegin();
	MutantStack<int>::reverse_iterator ite_r = mstack.rend();

	++it_r;
	--it_r;
	while (it_r != ite_r)
	{
		std::cout << *it_r << std::endl;
		++it_r;
	}
	std::cout << std::endl;

	{
		const MutantStack<int> aa(mstack);
		// const MutantStack<int> aa = mstack;

		MutantStack<int>::const_iterator it = aa.begin();

		while (it != aa.end())
		{
			std::cout << *it << std::endl;
			it++;
		}
	}

	return 0;
}
