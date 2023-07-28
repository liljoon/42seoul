#include "Span.hpp"

Span::Span() : max_len(0)
{
}

Span::~Span()
{
}

Span::Span(const Span &other) : max_len(other.max_len), v(other.v)
{
}

const Span &Span::operator=(const Span &other)
{
	if (this == &other)
		return (*this);

	v = other.v;
	max_len = other.max_len;

	return (*this);
}

Span::Span(unsigned int N) : max_len(N)
{
}

void Span::addNumber(int num)
{
	if (v.size() >= max_len)
		throw std::length_error("Max Length!");
	else
		v.push_back(num);
}

static void pre_check(const std::vector<int> &v)
{
	if (v.size() == 0 || v.size() == 1)
		throw std::logic_error("Too small vector");
}

unsigned int Span::shortestSpan()
{
	pre_check(v);

	unsigned int ret = UINT_MAX;
	std::vector<int> temp = v;

	std::sort(temp.begin(), temp.end());
	for (unsigned int i = 0; i < temp.size() - 1; i++)
	{
		if (static_cast<unsigned int>(temp[i + 1] - temp[i]) < ret)
			ret = temp[i + 1] - temp[i];
	}

	return ret;
}

unsigned int Span::longestSpan()
{
	pre_check(v);

	std::vector<int> temp = v;

	std::sort(temp.begin(), temp.end());

	return (temp[temp.size() - 1] - temp[0]);
}
