#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int raw_bits;
	static const int num_fractional_bits = 8;

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
};

std::ostream &operator<<(std::ostream &os, const Fixed &val);

#endif
