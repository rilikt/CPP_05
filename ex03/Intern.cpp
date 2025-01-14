/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:54:03 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 13:46:48 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {std::cout << "Default Intern constructor called" << std::endl;};

Intern::~Intern() {std::cout << "Intern destructor called" << std::endl;};

AForm* RobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* ShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* PresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	std::string str_arr[3] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
	AForm* (*fct_arr[3])(std::string) = {RobotomyForm, ShrubberyForm, PresidentialForm};

	for (int i = 0; i < 3; i++)
	{
		if (name == str_arr[i])
		{
			std::cout << "Intern creates form " << name << std::endl;
			return(fct_arr[i](target));
		}
	}
	std::cerr << "No matching form for " << name << " found" << std::endl;
	return(nullptr);
}
