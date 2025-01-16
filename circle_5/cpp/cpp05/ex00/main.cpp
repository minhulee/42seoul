/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 14:22:20 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	{
		// getter and operator<<
		Bureaucrat tommy("Tommy", 17);

		std::cout << "name : " << tommy.getName() << ", grade : " << tommy.getGrade() << std::endl;
		std::cout << tommy << std::endl;
	}
	std::cout << std::endl;

	{
		// Constructor in invalid grade
		try 
		{
			Bureaucrat	kane("Kane", 151);
		} 
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		// Too High
		Bureaucrat	tommy("Tommy", 1);
		
		try 
		{
			tommy.incrementGrade();
		} 
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
		tommy.decrementGrade();

		std::cout << tommy << std::endl;
	}
	std::cout << std::endl;

	{
		// Too Low
		Bureaucrat	tommy("Tommy", 150);

		try
		{
			tommy.decrementGrade();
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		tommy.incrementGrade();

		std::cout << tommy << std::endl;
	}
	
	return (0);
}