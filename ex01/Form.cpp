#include "Bureaucrat.hpp"
#include "Form.hpp"

// Con- Destructors

Form::Form(): name("<default form>"), sign(false), min_sign(150), min_exec(150)
{
	std::cout << "Default form constructor callled" << std::endl;
}

Form::Form(std::string name, int min_sign, int min_exec) : name(name), min_sign(min_sign), min_exec(min_exec)
{
	std::cout << "Form constructor called" << std::endl;
	if (min_sign < 1 || min_exec < 1)
		throw GradeTooHighException();
	else if (min_sign > 150 || min_exec > 150)
		throw GradeTooLowException();
	sign = false;
}

Form::Form(const Form &other) : name(other.name), min_sign(other.min_sign),
	min_exec(other.min_exec)
{
	std::cout << "Form copy constructor called" << std::endl;
	sign = false; // specified in .pdf to be false at construction
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

// Overload

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	std::cerr << "Constant values can be changed!" << std::endl;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form Name: " << f.getName() << "\n"
		<< "Is Signed: " << f.isSigned() << "\n"
		<< "Grade to sign requirement: " << f.getSignReq() << "\n"
		<< "Grade to execute requirement: " << f.getExecReq();
	return (os);
}

// Getters

std::string Form::getName() const
{
	return (this->name);
}

bool Form::isSigned() const
{
	return (this->sign);
}

int Form::getSignReq() const
{
	return (this->min_sign);
}

int Form::getExecReq() const
{
	return (this->min_exec);
}

// Exceptions

const char* Form::GradeTooHighException::what() const noexcept
{
	return ("Grade too high.");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("Grade too low.");
}

const char* Form::FormAlreadySigned::what() const noexcept
{
	return ("Form already signed.");
}

// Signing

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->min_sign && !this->sign)
		this->sign = true;
	else if (this->sign)
		throw FormAlreadySigned();
	else
		throw GradeTooLowException();
}
