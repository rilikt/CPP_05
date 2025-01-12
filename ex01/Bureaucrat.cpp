/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h4ns <h4ns@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:20:07 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/12 15:17:37 by h4ns             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructors and Destructor

Bureaucrat::Bureaucrat(std::string name, int grade): name(name) 
{
    if (grade > 150)
        GradeTooLowException();
    else if (grade < 1)
        GradeTooHighException();
    this->grade = grade;
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name) , grade(other.grade) {std::cout << "Bureaucrat copy constructor called" << std::endl;}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

// Overload

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;

    std::cerr << "Private name variable not assignable!" << std::endl;
    this->grade = other.grade; 

    return *this;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();

    return os;
}

// Exceptions

void Bureaucrat::GradeTooHighException()
{
    throw std::runtime_error("Grade too high and outside of maximum(1).");
}

void Bureaucrat::GradeTooLowException()
{
    throw std::runtime_error("Grade too low and under the minimum(150).");
}

// Getters and Setters

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::incrGrade(int n)
{
    if ((this->grade - n) < 1)
        GradeTooHighException();
    else
        this->grade -= n;
}

void Bureaucrat::decrGrade(int n)
{
    if ((this->grade += n) > 150)
        GradeTooLowException();
    else
        this->grade += n;
}

// Signing

void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << '\n';
        return;
    }
    std::cout << this->getName() << " signed " << f.getName() << std::endl;
    
}