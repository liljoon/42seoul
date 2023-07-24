#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

static void print_char(double inp)
{
	char ch = char(inp);

	std::cout << "char: ";

	if (ch < 33 || ch > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << ch << std::endl;
}

// static void print_int(double inp)
// {
// }

// static void print_float(double inp)
// {
// }

// static void print_double(double inp)
// {
// }

void ScalarConverter::convert(std::string str)
{
	double inp = strtod(str.c_str(), NULL);

	print_char(inp);
	std::cout << "int: " << (int)inp << std::endl;
	std::cout << "float: " << (float)inp << std::endl;
	std::cout << "double: " << inp << std::endl;
}
