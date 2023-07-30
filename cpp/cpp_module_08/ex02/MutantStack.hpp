#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <cstdlib>
#include <iterator>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
private:

public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);

	typedef typename Container::iterator iterator;
	typedef typename Container::reverse_iterator reverse_iterator;
	typedef typename Container::const_iterator const_iterator;
	typedef typename Container::const_reverse_iterator const_reverse_iterator;

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;
};

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other)
{

}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other)
{
	std::stack<T, Container>::operator=(other);

	return (*this);
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template <typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template <typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename Container::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template <typename T, typename Container>
typename Container::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}

#endif
