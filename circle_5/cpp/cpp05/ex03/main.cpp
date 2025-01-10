/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 19:09:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./Intern.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	
	Bureaucrat	b("b", 1);
	Intern		intern;
	AForm		*form;
	std::string	formList[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	std::cout << std::endl;
	
	intern.makeForm("?", "?");

	std::cout << std::endl;
	
	form = intern.makeForm(formList[0], "WHO!");

	std::cout << std::endl;
	
	b.signForm(*dynamic_cast<ShrubberyCreationForm *>(form));

	std::cout << std::endl;
	
	b.excuteForm(*dynamic_cast<ShrubberyCreationForm *>(form));

	std::cout << std::endl;

	delete(form);
	
	return (0);
}
