/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:01:08 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 16:21:20 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "AForm.hpp"

Intern::Intern()
{
	std::cout << "Intern :: Constructor() called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern :: Destructor() called" << std::endl;
}

AForm	*Intern::makeShrubberyCreationForm(const std::string target)
{
	std::cout << "Intern :: Method :: makeShrubberyCreationForm() called" << std::endl;
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobotomyRequestForm(const std::string target)
{
	std::cout << "Intern :: Method :: makeRobotomyRequestForm() called" << std::endl;
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePresidentialPardonForm(const std::string target)
{
	std::cout << "Intern :: Method :: makePresidentialPardonForm() called" << std::endl;
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string type, const std::string target)
{
	std::cout << "Intern :: Method :: makeForm() called" << std::endl;

	std::string	list[3] = {
		"shurubbery creation",
		"robotomy request",
		"Presidential pardon"
	};
	
	AForm	*(Intern::*creators[3])(const std::string) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (type == list[i])
			return (this->*creators[i])(target);
	}
	std::cerr << "Intern :: Exception :: Invalid Form Exception" << std::endl;
	return (NULL);
	//throw (InvalidFormException());
}

const char	*Intern::InvalidFormException::what() const throw()
{
	return ("Intern :: Exception :: Invalid Form Exception");
}
