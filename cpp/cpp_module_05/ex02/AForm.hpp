#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int signGrade;
	const int executeGrade;

	class GradeTooHighException : public std::exception
	{
	private:
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
	public:
		const char *what() const throw();
	};
	class NoSignException : public std::exception
	{
	private:
	public:
		const char *what() const throw();
	};

public:
	AForm();
	AForm(std::string _name, int _signGrade, int _executeGrade);
	~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat &br);
	virtual void execute(Bureaucrat const &executor) const = 0;
	void checkExecute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);

#endif
