/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:51:25 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/07 13:21:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"

Form::Form(const std::string name, const int signGrade, const int excuteGrade)
: name(name), isSigned(false), signGrade(validGrade(signGrade)), excuteGrade(validGrade(excuteGrade))
{
	std::cout << "Form :: Constructor called" << std::endl;
}

Form::Form(const Form &other)
: name(other.name), isSigned(false), signGrade(validGrade(other.signGrade)), excuteGrade(validGrade(other.excuteGrade))
{
	std::cout << "Form :: Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form :: Destructor called" << std::endl;
}

int	Form::validGrade(const int grade) const
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}
