#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	Bureaucrat(const std::string _name, const int _grade);
	std::string getName() const;
	int getGrade() const;
	void increaseGrade();
	void decreaseGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif
