#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->raw_bits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rb)
{
	raw_bits = rb << num_fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rb)
{
	raw_bits = roundf(rb * 256);
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

	return ((float)this->raw_bits / 256);
}

int Fixed::toInt(void) const
{
	return (int)(this->raw_bits >> 8);
}

bool Fixed::operator<(const Fixed &r)
{
	return this->raw_bits < r.raw_bits;
}

bool Fixed::operator>(const Fixed &r)
{
	return this->raw_bits > r.raw_bits;
}

bool Fixed::operator>=(const Fixed &r)
{
	return this->raw_bits >= r.raw_bits;
}

bool Fixed::operator<=(const Fixed &r)
{
	return this->raw_bits <= r.raw_bits;
}

bool Fixed::operator==(const Fixed &r)
{
	return this->raw_bits == r.raw_bits;
}

bool Fixed::operator!=(const Fixed &r)
{
	return this->raw_bits != r.raw_bits;
}

Fixed Fixed::operator+(const Fixed &r)
{
	Fixed ret;
	ret.raw_bits = this->raw_bits + r.raw_bits;
	return ret;
}

Fixed Fixed::operator-(const Fixed &r)
{
	Fixed ret;
	ret.raw_bits = this->raw_bits - r.raw_bits;
	return ret;
}

Fixed Fixed::operator*(const Fixed &r)
{
	Fixed ret;
	ret.raw_bits = (this->raw_bits * r.raw_bits) >> (num_fractional_bits);
	return ret;
}

Fixed Fixed::operator/(const Fixed &r)
{
	Fixed ret;
	ret.raw_bits = ((this->raw_bits << (num_fractional_bits)) / r.raw_bits);
	return ret;
}

std::ostream &operator<<(std::ostream &os, const Fixed &val)
{
	std::cout << val.toFloat();
	return os;
}
