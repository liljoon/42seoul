#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain : Default Constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain : Copy Constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain : Copy Assign Operator" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor" << std::endl;
}

void Brain::setIdeas(int idx, std::string input)
{
	ideas[idx] = input;
}

void Brain::printIdeas() const
{
	for (int i = 0; i < 100; i++)
		std::cout << i << " : " << ideas[i] << std::endl;
}