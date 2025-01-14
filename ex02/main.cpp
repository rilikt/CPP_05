/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:51 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 12:48:31 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << G << "| - Creating Objects - |" << std::endl;
	
		Bureaucrat a("Ali" , 1);
		// Bureaucrat a("Ali" , 100);
		// AForm f("Form", 5, 5);
		PresidentialPardonForm p("Ali");
		ShrubberyCreationForm s("Tree");
		RobotomyRequestForm r("Bender");

	std::cout << Y << "| - Testing - |" << std::endl;

		std::cout << p << std::endl;
		a.signForm(s);
		a.executeForm(s);

		a.signForm(r);
		a.executeForm(r);
	
		try
		{
			a.signForm(p);
			a.executeForm(p);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		
	std::cout << Ro << "| - Destruction - |" << std::endl;
	
	return(0);
}
