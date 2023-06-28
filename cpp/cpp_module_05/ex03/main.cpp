#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		Intern someRandomIntern;
		AForm *rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		delete rrf;

		rrf = someRandomIntern.makeForm("Wrong!", "Bender");
	}
	std::cout << std::endl;
	{
		Intern someRandomIntern;
		AForm *rrf;
		Bureaucrat br("tester", 14);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		// rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		br.signForm(*rrf);
		br.executeForm(*rrf);
		delete rrf;
	}
}
