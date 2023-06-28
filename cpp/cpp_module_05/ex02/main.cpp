#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat br("test1", 137);
		// Bureaucrat br("test1", 138);
		// Bureaucrat br("test1", 139);
		ShrubberyCreationForm scf("test1");

		br.executeForm(scf);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
