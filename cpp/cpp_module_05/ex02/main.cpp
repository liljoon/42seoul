#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{
	try
	{
		Bureaucrat br("test1", 137);
		Bureaucrat br2("test2", 140);

		// Bureaucrat br("test1", 138);
		// Bureaucrat br("test1", 139);
		ShrubberyCreationForm scf("test_form");

		br.signForm(scf);
		// br2.signForm(scf);
		br.executeForm(scf);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat br("test1", 50);
		Bureaucrat br2("test2", 40);

		RobotomyRequestForm robo("test_robo");

		br.signForm(robo);

		// br.executeForm(robo);
		br2.executeForm(robo);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat br("test1", 1);
		Bureaucrat br2("test2", 20);

		PresidentialPardonForm pres("test_pres");

		br.signForm(pres);

		// br.executeForm(pres);
		br2.executeForm(pres);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
