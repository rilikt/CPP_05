/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:02:11 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 10:38:00 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define R "\033[0m"
#define Bl "\033[30m"
#define Ro "\033[31m"
#define G "\033[32m"
#define Y "\033[33m"
#define B "\033[34m"
#define M "\033[35m"

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
