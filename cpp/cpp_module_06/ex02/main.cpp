#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	std::srand(std::time(0));
	int ran_int = std::rand() % 3;

	Base *ret;

	if (ran_int == 0)
		ret = new A;
	else if (ran_int == 1)
		ret = new B;
	else
		ret = new C;

	return ret;
}

void identify(Base *p)
{
	A *a_ptr = dynamic_cast<A *>(p);
	B *b_ptr = dynamic_cast<B *>(p);
	C *c_ptr = dynamic_cast<C *>(p);

	if (a_ptr)
		std::cout << "A" << std::endl;
	if (b_ptr)
		std::cout << "B" << std::endl;
	if (c_ptr)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a_ptr = dynamic_cast<A &>(p);
		(void)a_ptr;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		B &b_ptr = dynamic_cast<B &>(p);
		(void)b_ptr;
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		C &c_ptr = dynamic_cast<C &>(p);
		(void)c_ptr;
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
}

int main()
{
	Base *b = generate();

	identify(b);
	identify(*b);
}
