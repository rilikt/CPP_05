/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:54:01 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 13:41:19 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
  private:
  public:
	//Con- Destructor
	Intern();
	Intern(const Intern &other) = delete;
	~Intern();

	//Overload
	Intern& operator=(const Intern &other) = delete;

	//Create Form
	AForm* makeForm(std::string name, std::string target) const;
};