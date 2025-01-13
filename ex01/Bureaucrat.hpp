/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:52:21 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:21:30 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
// #include "Form.hpp"
class Form;

class Bureaucrat
{
  private:
	const std::string name;
	int grade;

	class GradeTooHighException: public std::exception
	{
		const char* what() const noexcept override;
	};

	class GradeTooLowException: public std::exception
	{
		const char* what() const noexcept override;
	};

  public:
	Bureaucrat(); // default constructor
	Bureaucrat(std::string name, int grade);
	~Bureaucrat(); // default destructor
	Bureaucrat(const Bureaucrat &other); // copy constructor
	Bureaucrat& operator=(const Bureaucrat &other) = delete; // assignment overload

	// Getter and Setter
	std::string getName() const;
	int getGrade() const;

	void incrGrade(int n);
	void decrGrade(int n);

	// Signing
	void signForm(Form &f);
};

std::ostream& operator<<(std::ostream &os, const Bureaucrat &b);
