/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:46:08 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main(void)
{
	{
		try
		{
			Form	f("f", 0, 100);
			
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Form	f("f", 151, 100);
			
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Form		f("f", 5, 100);
		Bureaucrat	b("b", 6);

		std::cout << f.getName() << ", " << f.getSignGrade() << ", " << f.getExcuteGrade() << ", " << f.getIsSigned() << "." << std::endl;
		b.signForm(f);
		//b = Bureaucrat("tmp", 1);
		b.signForm(f);
		std::cout << f;
	}
	
	return (0);
}
