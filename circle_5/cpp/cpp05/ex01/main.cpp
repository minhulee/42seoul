/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/07 12:35:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	{
		// getter
		Bureaucrat tommy("Tommy", 17);

		std::cout << "name : " << tommy.getGrade() << ", grade : " << tommy.getGrade() << std::endl;
	}

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
	}

	// Constructor in invalid grade
	try 
	{
		Bureaucrat	kane("Kane", 151);
	} 
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}