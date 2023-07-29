#include "RPN.hpp"

enum OperType
{
	PLUS = 10,
	MINUS,
	DIVIDE,
	MULTIPLY
};

void error_exit()
{
	std::cout << "Error" << std::endl;
	std::exit(1);
}

int check_input(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c == '+')
		return PLUS;
	else if (c == '-')
		return MINUS;
	else if (c == '/')
		return DIVIDE;
	else if (c == '*')
		return MULTIPLY;
	else
		return -1;
}

void calc_oper(int oper, std::stack<int> &st)
{
	int first, second, result;

	if (st.size() < 2)
		error_exit();
	second = st.top();
	st.pop();
	first = st.top();
	st.pop();

	if (oper == PLUS)
		result = first + second;
	else if (oper == MINUS)
		result = first - second;
	else if (oper == DIVIDE)
		result = first / second;
	else if (oper == MULTIPLY)
		result = first * second;

	st.push(result);

	return;
}

int RPN(std::string expression)
{
	std::stack<int> st;
	std::stringstream ss(expression);

	char input;

	while (ss >> input)
	{
		int result = check_input(input);

		if (result == -1)
			error_exit();
		else if (result >= 0 && result <= 9)
			st.push(result);
		else
			calc_oper(result, st);
	}
	if (st.size() != 1)
		error_exit();

	return st.top();
}
