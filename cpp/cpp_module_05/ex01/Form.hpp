#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

public:
	Form();
	Form(std::string _name, int _signGrade, int _executeGrade);
	~Form();
	Form(const Form &other);
	Form operator=(const Form &other);

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;

	void beSigned(Bureaucrat &br);
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif
