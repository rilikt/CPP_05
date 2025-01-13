/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:38:59 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 17:04:15 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Con- Destructor

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", "<default target>", 145, 137)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm("ShrubberyCreationForm", other.getTarget(), 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout <<  "ShrubberyCreationForm destructor called" << std::endl;
}

//Overload

void ShrubberyCreationForm::task(std::string target) const
{
	std::ofstream output(target.append("_shrubbery"));
	output <<"                    ___\n";

	output.close();

}