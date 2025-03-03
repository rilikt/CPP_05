/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:51 by timschmi          #+#    #+#             */
/*   Updated: 2025/03/03 16:28:33 by timschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat a("Ali" , 10);
	Bureaucrat m("Max", 150);
	Bureaucrat b;

	std::cout << b << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << a << std::endl;

		try
		{
			a.incrGrade(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
	}

	try
	{
		Bureaucrat a("Mon", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return(0);
}
