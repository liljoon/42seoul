#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string _name, std::string _target)
{
	int ret_idx = -1;

	const std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	AForm *formPtrArr[] = {
		new ShrubberyCreationForm(_target),
		new RobotomyRequestForm(_target),
		new PresidentialPardonForm(_target)};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == _name)
			ret_idx = i;
		else
			delete formPtrArr[i];
	}
	if (ret_idx == -1)
	{
		std::cout << "Wrong Name!" << std::endl;

		return nullptr;
	}
	std::cout << "Intern creates " << _name << std::endl;

	return formPtrArr[ret_idx];
}
