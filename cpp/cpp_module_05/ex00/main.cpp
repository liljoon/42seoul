#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("tester_high", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("tester_low", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("tester_150", 150);
		std::cout << b << std::endl;
		b.decreaseGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("tester_1", 1);
		std::cout << b << std::endl;
		b.increaseGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat b("tester_normal", 3);
		std::cout << b << std::endl;
		b.increaseGrade();
		std::cout << b << std::endl;
		b.decreaseGrade();
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
