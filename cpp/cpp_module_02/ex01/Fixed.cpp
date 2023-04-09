#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->raw_bits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rb)
{
	//
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rb)
{
	//
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	this->raw_bits = other.raw_bits;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	this->raw_bits = other.raw_bits;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return this->raw_bits;
}

void Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
}

float Fixed::toFloat(void) const
{
	//
	return ret;
}

int Fixed::toInt(void) const
{
	//
	return ret;
}

std::ostream &operator<<(std::ostream &os, const Fixed &val)
{
}