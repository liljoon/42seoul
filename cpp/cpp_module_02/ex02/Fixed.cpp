#include "Fixed.hpp"
#include <cmath>

static const int num_fractional_bits = 8;

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
	raw_bits = roundf(rb * std::pow(2, num_fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->raw_bits = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = other.getRawBits();
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

	return ((float)this->raw_bits / std::pow(2, num_fractional_bits));
}

int Fixed::toInt(void) const
{
	return (int)(this->raw_bits >> num_fractional_bits);
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

Fixed &Fixed::operator++()
{
	raw_bits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	raw_bits += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	raw_bits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	raw_bits -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.raw_bits <= b.raw_bits)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.raw_bits <= b.raw_bits)
		return a;
	else
		return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.raw_bits >= b.raw_bits)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.raw_bits >= b.raw_bits)
		return a;
	else
		return b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &val)
{
	os << val.toFloat();
	return os;
}
