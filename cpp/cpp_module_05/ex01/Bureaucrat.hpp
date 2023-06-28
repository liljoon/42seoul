#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

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
	Bureaucrat();
	Bureaucrat(const std::string _name, const int _grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;

	void increaseGrade();
	void decreaseGrade();
	void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
