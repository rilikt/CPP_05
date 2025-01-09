
#pragma once

#include <iostream>

class Bureaucrat
{
	private:
	const std::string name;
	int grade;

	public:
	// Bureaucrat(); // void constructor

	Bureaucrat(std::string name, int grade); // default constructor
	// ~Bureaucrat(); // default destructor
	// Bureaucrat(const Bureaucrat &other); // copy constructor
	// Bureaucrat& operator=(const Bureaucrat &other); // assignment overload

	// std::string getName() const;
	// int getGrade() const;

};