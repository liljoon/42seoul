#include <iostream>
#include "print_utils.hpp"

void print_standard(int m)
{
	if (m < 10)
		std::cout << '0';
	std::cout << m;
}

void print_timestamp()
{
	time_t time_now;
	tm *tm;

	time(&time_now);
	tm = localtime(&time_now);
	std::cout << '[' << tm->tm_year + 1900;
	print_standard(tm->tm_mon + 1);
	print_standard(tm->tm_mday);
	std::cout << '_';
	print_standard(tm->tm_hour);
	print_standard(tm->tm_min);
	print_standard(tm->tm_sec);
	std::cout << "] ";
}

void print_index(int idx)
{
	std::cout << "index:" << idx << ';';
}

void print_amount(int amount)
{
	std::cout << "amount:" << amount << ';';
}

void print_deposits(int deposits)
{
	std::cout << "deposits:" << deposits << ';';
}

void print_withdrawals(int withdrawals)
{
	std::cout << "withdrawals:" << withdrawals;
}
