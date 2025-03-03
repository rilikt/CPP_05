/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:51 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/03 16:54:06 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

//use rand() or std::rand()??

int main(void)
{
	AForm *f;

	std::cout << G << "| - Creating Objects - |" << std::endl;

	Intern i;

	std::cout << Y << "| - Testing - |" << std::endl;

	f = i.makeForm("RobotomyRequestForm", "Bender");
	if(f)
	{
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;
	}
	f = i.makeForm("PresidentialPardonForm", "Bender");
	if(f)
	{
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;
	}
	f = i.makeForm("ShrubberyCreationForm", "Bender");
	if(f)
	{
		std::cout << *f << std::endl;
		delete f;
		std::cout << std::endl;
	}

	std::cout << Ro << "| - Destruction - |" << R << std::endl;
	
	return(0);
}
