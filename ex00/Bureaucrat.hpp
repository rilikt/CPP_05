
#pragma once

#include <iostream>

class Bureaucrat
{
	private:
	const std::string name;
	int grade;
	void GradeTooHighException();
	void GradeTooLowException();

	public:
	// Bureaucrat(); // void constructor

	Bureaucrat(std::string name, int grade); // default constructor
	~Bureaucrat(); // default destructor
	Bureaucrat(const Bureaucrat &other); // copy constructor
	Bureaucrat& operator=(const Bureaucrat &other); // assignment overload

	// Getter and Setter
	std::string getName() const;
	int getGrade() const;

	void incrGrade(int n);
	void decrGrade(int n);

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);