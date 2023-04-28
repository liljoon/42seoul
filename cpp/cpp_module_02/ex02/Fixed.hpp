#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int raw_bits;
	static const int num_fractional_bits;

public:
	Fixed();
	Fixed(const int rb);
	Fixed(const float rb);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	bool operator<(const Fixed &r);
	bool operator>(const Fixed &r);
	bool operator>=(const Fixed &r);
	bool operator<=(const Fixed &r);
	bool operator==(const Fixed &r);
	bool operator!=(const Fixed &r);

	Fixed operator+(const Fixed &r);
	Fixed operator-(const Fixed &r);
	Fixed operator*(const Fixed &r);
	Fixed operator/(const Fixed &r);

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &val);

#endif
