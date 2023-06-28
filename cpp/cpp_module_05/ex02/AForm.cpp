#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), signGrade(150), executeGrade(150)
{
}

AForm::AForm(std::string _name, int _signGrade, int _executeGrade) : name(_name), isSigned(false), signGrade(_signGrade), executeGrade(_executeGrade)
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

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(false), signGrade(other.signGrade), executeGrade(other.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
	isSigned = other.isSigned;

	return *this;
}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->executeGrade;
}

void AForm::beSigned(Bureaucrat &br)
{
	if (br.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->isSigned = true;
}

void AForm::checkExecute(Bureaucrat const &executor) const
{
	if (this->executeGrade < executor.getGrade())
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "name : " << f.getName() << std::endl;
	os << "isSigned : " << f.getIsSigned() << std::endl;
	os << "signGrade : " << f.getSignGrade() << std::endl;
	os << "executeGrade : " << f.getExecuteGrade() << std::endl;

	return os;
}
