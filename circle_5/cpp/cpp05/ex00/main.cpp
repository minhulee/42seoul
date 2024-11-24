/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/11 16:24:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat	high("Tommy", 1);
		
		try 
		{
			high.incrementGrade();
		} 
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		
		high.decrementGrade();

		std::cout << high << std::endl;
	}

	try 
	{
		Bureaucrat	low("Tommy", 151);
	} 
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}