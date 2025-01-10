/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:04:21 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:19:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm :: Constructor() called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
: AForm(other), target(other.target)
{
	std::cout << "PresidentialPardonForm :: Copy Constructor() called" << std::endl;;
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm :: Destructor() called" << std::endl ;
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (target);
}

void	PresidentialPardonForm::excute(const Bureaucrat &br) const
{
	std::cout << "PresidentialPardonForm :: Methods :: excute() called" << std::endl;
	validFormSigned();
	validExcuteGrade(br.getGrade());
	std::cout << getTarget() << " has been pardoned by Zaphod Beebleborx." << std::endl;
}
