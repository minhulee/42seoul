/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 17:01:23 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./Intern.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShrubberyCreationForm.hpp"

int main(void)
{
	srand(time(0));
	
	Bureaucrat	b("b", 1);
	Intern		intern;
	AForm		*form;
	std::string	formList[3] = {
		"shurubbery creation",
		"robotomy request",
		"Presidential pardon"
	};

	std::cout << std::endl;
	
	// invalid form format
	intern.makeForm("?", "?");
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << std::endl;

		form = intern.makeForm(formList[i], "WHO!");

		std::cout << std::endl;
		
		b.signForm(*form);

		std::cout << std::endl;
		
		b.excuteForm(*form);

		std::cout << std::endl;

		delete(form);
	}
	
	return (0);
}
