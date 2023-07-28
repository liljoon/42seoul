#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <vector>

template <typename T>
class MutantStack
{
private:
	vector<int> v;

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
};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	return (*this);
}

template <typename T>
bool MutantStack<T>::empty() const
{
	return false;
}

template <typename T>
size_t MutantStack<T>::size() const
{
	return size_t();
}

template <typename T>
T &MutantStack<T>::top()
{
	// TODO: insert return statement here
}

template <typename T>
const T &MutantStack<T>::top() const
{
	// TODO: insert return statement here
}

template <typename T>
void MutantStack<T>::push(const T &val)
{
}

template <typename T>
void MutantStack<T>::pop()
{
}

#endif
