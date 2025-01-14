/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:14:03 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/14 16:34:08 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  private:

  public:
  // Con- Destructor
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	~PresidentialPardonForm();
  // Overload
	PresidentialPardonForm& operator=(const PresidentialPardonForm &other) = delete;
	void task(std::string target) const override;
};
