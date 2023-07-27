#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	arr = NULL;
	size = 0;
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
	unsigned int other_len = other.size;

	arr = new T[other_len];
	size = other_len;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	for (unsigned int i = 0; i < this->size; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arr = new T[n];
	size = n;
	std::memset(arr, 0, sizeof(T));
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= size)
		throw std::out_of_range("Index out of bounds!");
	return this->arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->size;
}
