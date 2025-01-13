/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:20:07 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:27:56 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors and Destructor

Bureaucrat::Bureaucrat() : name("<default>"), grade(150){};

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name),
	grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

// Overload

// Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
// {
// 	if (this == &other)
// 		return (*this);
// 	std::cerr << "Private name variable not assignable!" << std::endl;
// 	this->grade = other.grade;
// 	return (*this);
// }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

// Exceptions

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return ("Grade too high and outside of maximum(1).");
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return ("Grade too low and under the minimum(150).");
}

// Getters and Setters

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrGrade(int n)
{
	if ((this->grade - n) < 1)
		throw GradeTooHighException();
	else
		this->grade -= n;
}

void Bureaucrat::decrGrade(int n)
{
	if ((this->grade += n) > 150)
		throw GradeTooLowException();
	else
		this->grade += n;
}
