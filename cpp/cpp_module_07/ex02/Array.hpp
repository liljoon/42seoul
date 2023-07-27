#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstring>
#include <exception>

template <typename T>
class Array
{
private:
	T *arr;
	unsigned int len;

public:
	Array();
	~Array();
	Array(const Array &other);
	Array &operator=(const Array &other);
	Array(unsigned int n);

	T &operator[](unsigned int index);
	unsigned int size() const;
};

template <typename T>
Array<T>::Array()
{
	arr = new T[0];
	len = 0;
}

template <typename T>
Array<T>::~Array()
{
	if (arr)
		delete[] arr;
	arr = NULL;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	unsigned int other_len = other.len;

	arr = new T[other_len];
	len = other_len;
	for (unsigned int i = 0; i < this->len; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return (*this);

	if (arr)
		delete[] arr;

	unsigned int other_len = other.len;

	arr = new T[other_len];
	len = other_len;
	for (unsigned int i = 0; i < this->len; i++)
		this->arr[i] = other.arr[i];

	return (*this);
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	len = n;
	std::memset(arr, 0, sizeof(T) * n);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::exception();
	return this->arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->len;
}

#endif
