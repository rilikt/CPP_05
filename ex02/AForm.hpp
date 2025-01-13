/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:02:11 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:21:08 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

// #include "Bureaucrat.hpp"
class	Bureaucrat;

class AForm
{
  private:
	const std::string name;
	const std::string target;
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
	class FormNotSigned : public std::exception
	{
		const char *what() const noexcept override;
	};

  public:
	// Constructors, Destructors
	AForm();
	AForm(std::string name, std::string target, int min_sign, int min_exec);
	AForm(const AForm &other);
	virtual ~AForm();

	// Overload
	AForm &operator=(const AForm &other) = delete;

	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getSignReq() const;
	int getExecReq() const;
	std::string getTarget() const;

	// Signing
	void beSigned(const Bureaucrat &b);

	//Execution
	void execute(const Bureaucrat &executor) const;
	virtual void task(std::string target) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
