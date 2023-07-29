#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		error_exit();
	std::cout << RPN(argv[1]) << std::endl;
}
