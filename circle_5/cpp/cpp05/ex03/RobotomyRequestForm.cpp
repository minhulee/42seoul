/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:04:21 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:19:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm :: Constructor() called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), target(other.target)
{
	std::cout << "RobotomyRequestForm :: Copy Constructor() called" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm :: Destructor() called" << std::endl ;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (target);
}

void	RobotomyRequestForm::excute(const Bureaucrat &br) const
{
	std::cout << "RobotomyRequestForm :: Methods :: excute() called" << std::endl;
	validFormSigned();
	validExcuteGrade(br.getGrade());
	std::cout << "DRRRRRRRRR... DRRRRRRRR !!!!!!!!!" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully !" << std::endl;
	else
		std::cout << getTarget() << " has been failed... sorry.." << std::endl;
}
