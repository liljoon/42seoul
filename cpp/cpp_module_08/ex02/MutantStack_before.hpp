#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <cstdlib>
#include <iterator>

template <typename T, typename Container = std::deque<T>>
class MutantStack
{
private:
	Container dque;

public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	// canonical form

	bool empty() const;
	size_t size() const;
	T &top();
	const T &top() const;
	void push(const T &val);
	void pop();

	// using iterator = std::iterator;
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
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &other)
{
	dque = other.dque;
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other)
{
	if (this != &other)
		dque = other.dque;
	return (*this);
}

template <typename T, typename Container>
bool MutantStack<T, Container>::empty() const
{
	return dque.empty();
}

template <typename T, typename Container>
size_t MutantStack<T, Container>::size() const
{
	return dque.size();
}

template <typename T, typename Container>
T &MutantStack<T, Container>::top()
{
	return dque.back();
}

template <typename T, typename Container>
const T &MutantStack<T, Container>::top() const
{
	return dque.back();
}

template <typename T, typename Container>
void MutantStack<T, Container>::push(const T &val)
{
	dque.push_back(val);
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop()
{
	dque.pop_back();
}

#endif
