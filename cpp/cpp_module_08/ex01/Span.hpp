#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <climits>
#include <iterator>

class Span
{
private:
	unsigned int max_len;
	std::vector<int> v;

public:
	Span();
	~Span();
	Span(const Span &other);
	const Span &operator=(const Span &other);

	Span(unsigned int N);
	void addNumber(int num);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename Iterator>
	void addByIterator(Iterator first, Iterator last)
	{
		std::vector<int> temp = v;

		temp.insert(v.end(), first, last);
		if (temp.size() > max_len)
			throw std::length_error("Max Length!");
		else
			v = temp;
	}
};

#endif
