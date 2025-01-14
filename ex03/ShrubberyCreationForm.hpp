/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:33:06 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/13 16:50:12 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#include <string>

class ShrubberyCreationForm: public AForm
{
  private:

  public:
  //Con- Destructor
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm();
  //Overload
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other) = delete;
	void task(std::string target) const override;
};
