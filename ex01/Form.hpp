/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:56:43 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:21:41 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// #include "Bureaucrat.hpp"
class	Bureaucrat;

class Form
{
  private:
	const std::string name;
	bool sign;
	const int min_sign;
	const int min_exec;

	// Exceptions
	class GradeTooHighException : public std::exception
	{
		const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		const char *what() const noexcept override;
	};
	class FormAlreadySigned : public std::exception
	{
		const char *what() const noexcept override;
	};

  public:
	// Constructors, Destructors
	Form();
	Form(std::string name, int min_sign, int min_exec);
	Form(const Form &other);
	~Form();

	// Overload
	Form &operator=(const Form &other) = delete;

	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getSignReq() const;
	int getExecReq() const;

	// Signing
	void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &f);
