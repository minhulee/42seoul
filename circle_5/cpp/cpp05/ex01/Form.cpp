/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:51:25 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/14 21:35:32 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form(const std::string name, const int signGrade, const int excuteGrade)
: name(name), isSigned(false), signGrade(validGradeRange(signGrade)), excuteGrade(validGradeRange(excuteGrade))
{
	std::cout << "Form :: Constructor called" << std::endl;
}

Form::Form(const Form &other)
: name(other.name), isSigned(false), signGrade(validGradeRange(other.signGrade)), excuteGrade(validGradeRange(other.excuteGrade))
{
	std::cout << "Form :: Copy Constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form :: Destructor called" << std::endl;
}

std::string	Form::getName() const
{
	// std::cout << "Form :: Method :: getName() called" << std::endl;
	return (name);
}

bool	Form::getIsSigned() const
{
	// std::cout << "Form :: Method :: getIsSigned() called" << std::endl;
	return (isSigned);
}

int	Form::getSignGrade() const
{
	// std::cout << "Form :: Method :: getSignGrade() called" << std::endl;
	return (signGrade);
}

int	Form::getExcuteGrade() const
{
	// std::cout << "Form :: Method :: getExcuteGrade() called" << std::endl;
	return (excuteGrade);
}

int	Form::validGradeRange(const int grade) const
{
	std::cout << "Form :: Method :: validGrade() called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	Form::validSignGrade(const int grade) const
{
	if (getSignGrade() < grade)
		throw GradeTooLowException();
}

void	Form::beSigned(const Bureaucrat &br)
{
	std::cout << "Form :: Method :: beSigned() called" << std::endl;
	validSignGrade(br.getGrade());
	isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form :: exception :: Grade Too High Exception";
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form :: exception :: Grade Too Low Exception";
}

std::ostream&	operator<<(std::ostream &os, Form &f)
{
	os << f.getName() << ", signGrade : " << f.getSignGrade() << ", excuteGrade : " << f.getExcuteGrade() << ", signed : " << (f.getIsSigned() ? "true" : "false") << "." << std::endl;
	return os;
}
