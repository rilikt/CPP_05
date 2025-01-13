/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:02:36 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:03:06 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Con- Destructors

AForm::AForm(): name("<default form>"), target("<default target>"), sign(false), min_sign(150), min_exec(150)
{
	std::cout << "Default form constructor callled" << std::endl;
}

AForm::AForm(std::string name, std::string target, int min_sign, int min_exec) : name(name), target(target), min_sign(min_sign), min_exec(min_exec)
{
	std::cout << "Form constructor called" << std::endl;
	if (min_sign < 1 || min_exec < 1)
		throw GradeTooHighException();
	else if (min_sign > 150 || min_exec > 150)
		throw GradeTooLowException();
	sign = false;
}

AForm::AForm(const AForm &other) : name(other.name), min_sign(other.min_sign), min_exec(other.min_exec)
{
	std::cout << "Form copy constructor called" << std::endl;
	sign = false; // specified in .pdf to be false at construction
}

AForm::~AForm()
{
	std::cout << "Form Destructor called" << std::endl;
}

// Overload

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	std::cerr << "Constant values can be changed!" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "Form Name: " << f.getName() << "\n"
		<< "Is Signed: " << f.isSigned() << "\n"
		<< "Grade to sign requirement: " << f.getSignReq() << "\n"
		<< "Grade to execute requirement: " << f.getExecReq();
	return (os);
}

// Getters

std::string AForm::getName() const
{
	return (this->name);
}

bool AForm::isSigned() const
{
	return (this->sign);
}

int AForm::getSignReq() const
{
	return (this->min_sign);
}

int AForm::getExecReq() const
{
	return (this->min_exec);
}

std::string AForm::getTarget() const
{
	return (this->target);
}

// Exceptions

const char* AForm::GradeTooHighException::what() const noexcept
{
	return ("Grade too high.");
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return ("Grade too low.");
}

const char* AForm::FormAlreadySigned::what() const noexcept
{
	return ("Form already signed.");
}

const char* AForm::FormNotSigned::what() const noexcept
{
	return ("Form not signed.");
}

// Signing

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->min_sign && !this->sign)
		this->sign = true;
	else if (this->sign)
		throw FormAlreadySigned();
	else
		throw GradeTooLowException();
}

// Execution

void AForm::execute(const Bureaucrat &executor) const
{
	if (!this->sign)
		throw FormNotSigned();
	else if (executor.getGrade() > this->getExecReq())
		throw GradeTooLowException();
	if (this->sign && executor.getGrade() <= this->getExecReq())
		this->task(this->target);
}
