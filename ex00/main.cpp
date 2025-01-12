/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: h4ns <h4ns@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:07:51 by timschmi          #+#    #+#             */
/*   Updated: 2025/01/12 13:09:05 by h4ns             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("Ali" , 10);

	for (int i = 0; i < 10; i++)
	{
		std::cout << b << std::endl;

		try
		{
			b.incrGrade(1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		
	}

	// try
	// {
	// 	Bureaucrat a("Mon", 200);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << "Exception caught: " << e.what() << std::endl;
	// }
	
	return(0);
}