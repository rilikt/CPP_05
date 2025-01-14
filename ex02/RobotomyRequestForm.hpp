/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:45:27 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 16:33:57 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
  private:
  public:
	//Con- Destructor
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	~RobotomyRequestForm();

	//Overload
	RobotomyRequestForm& operator=(const RobotomyRequestForm &other) = delete;
	void task(std::string target) const override;
};