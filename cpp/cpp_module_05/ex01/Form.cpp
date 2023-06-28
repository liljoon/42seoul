#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
}

Form::Form(std::string _name, int _signGrade, int _executeGrade) : name(_name), isSigned(false), signGrade(_signGrade), executeGrade(_executeGrade)
{
	if (_signGrade > 150)
		throw GradeTooLowException();
	else if (_signGrade < 1)
		throw GradeTooHighException();

	if (_executeGrade > 150)
		throw GradeTooLowException();
	else if (_executeGrade < 1)
		throw GradeTooHighException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : name(other.name), isSigned(false), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
	isSigned = other.isSigned;

	return *this;
}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecuteGrade() const
{
	return this->executeGrade;
}

void Form::beSigned(Bureaucrat &br)
{
	if (br.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "name : " << f.getName() << std::endl;
	os << "isSigned : " << f.getIsSigned() << std::endl;
	os << "signGrade : " << f.getSignGrade() << std::endl;
	os << "executeGrade : " << f.getExecuteGrade() << std::endl;

	return os;
}
