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

static bool check_char(std::string str)
{
	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return true;
	else
		return false;
}

static void print_char(char ch)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	std::cout << "char: '" << ch << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(ch) << std::endl;
	std::cout << "float: " << static_cast<float>(ch) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(ch) << std::endl;
}

static bool check_int(std::string str)
{
	if (std::to_string(std::atoi(str.c_str())) == str)
		return true;
	else
		return false;
}

static void print_int(int num)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	if (num < -128 || num > 127)
		std::cout << "char: overflow" << std::endl;
	else if (num < 33 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << num << std::endl;
	std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static bool check_float(std::string str)
{
	if (str[str.length() - 1] == 'f' && str != "inf" && str != "-inf")
		return true;
	else
		return false;
}

static void print_float(float num)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	if (std::isnan(num)) // err
		std::cout << "char: impossible" << std::endl;
	else if (num < -128 || num > 127)
		std::cout << "char: overflow" << std::endl;
	else if (num < 33 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	if (std::isnan(num))
		std::cout << "int: impossible" << std::endl;
	else if (num > INT_MAX || num < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;

	std::cout << "float: " << num << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void print_double(double num)
{
	std::cout << std::fixed;
	std::cout.precision(1);
	if (std::isnan(num))
		std::cout << "char: impossible" << std::endl;
	else if (num < -128 || num > 127)
		std::cout << "char: overflow" << std::endl;
	else if (num < 33 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	if (std::isnan(num))
		std::cout << "int: impossible" << std::endl;
	else if (num > INT_MAX || num < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (!(num == INFINITY || num == -INFINITY) && (num > FLT_MAX || num < -FLT_MAX))
		std::cout << "float: overflow" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << num << std::endl;
}

void ScalarConverter::convert(std::string str)
{
	if (check_char(str))
		print_char(str[0]);
	else if (check_int(str))
		print_int(std::atoi(str.c_str()));
	else if (check_float(str))
		print_float(strtof(str.c_str(), NULL));
	else
		print_double(strtod(str.c_str(), NULL));
}
