/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:49:04 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/18 11:32:50 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

//Con- Destructor

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", "<default target>", 72, 45)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm("RobotomyRequestForm", other.getTarget(), 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

//Overload

void RobotomyRequestForm::task(std::string target) const
{
	std::time_t time = std::time(nullptr);
	srand(static_cast<unsigned int>(time));

	std::cout << "Brrrr.. BRRRRR.." << std::endl; 

	if (rand() % 2 == 0)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy on " << target << " has failed :(" << std::endl;
}
