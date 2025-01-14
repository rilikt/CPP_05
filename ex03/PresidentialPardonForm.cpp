/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:20:52 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:28:14 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//Con- Destructor

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", "<default target>", 25, 5)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm("PresidentialPardonForm", other.getTarget(), 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for PresidentialPardonForm called" << std::endl;
}

//Overload

void PresidentialPardonForm::task(std::string target) const
{
	std::cout << "President Zaphod Beeblebrox has pardoned " << target << std::endl;
}
