/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:44:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	Bureaucrat	b("b", 1);
	Bureaucrat	b2("b2", 150);
	
	// 145, 137
	ShrubberyCreationForm	sb("target_1");
	// 72, 45
	RobotomyRequestForm		rb("target_2");
	// 25, 5
	PresidentialPardonForm	pd("target_3");

	std::cout << std::endl ;
	b.signForm(sb);
	b.signForm(rb);
	b.signForm(pd);
	std::cout << std::endl;
	b.excuteForm(sb);
	b.excuteForm(rb);
	b.excuteForm(pd);
	std::cout << std::endl ;
	
	return (0);
}
