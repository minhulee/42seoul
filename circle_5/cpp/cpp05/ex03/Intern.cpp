/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:01:08 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 19:18:47 by minhulee         ###   ########seoul.kr  */
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
	list[0] = "ShrubberyCreationForm";
	list[1] = "RobotomyRequestForm";
	list[2] = "PresidentialPardonForm";
	creators[0] = &Intern::makeShrubberyCreationForm;
    creators[1] = &Intern::makeRobotomyRequestForm;
    creators[2] = &Intern::makePresidentialPardonForm;

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
