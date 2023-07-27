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

#endif
