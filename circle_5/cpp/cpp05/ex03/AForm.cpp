/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:51:25 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:39:44 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

AForm::AForm(const std::string name, const int signGrade, const int excuteGrade)
: name(name), isSigned(false), signGrade(validGradeRange(signGrade)), excuteGrade(validGradeRange(excuteGrade))
{
	std::cout << "AForm :: Constructor() called" << std::endl;
}

AForm::AForm(const AForm &other)
: name(other.name), isSigned(false), signGrade(validGradeRange(other.signGrade)), excuteGrade(validGradeRange(other.excuteGrade))
{
	std::cout << "AForm :: Copy Constructor() called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm :: Destructor() called" << std::endl;
}

std::string	AForm::getName() const
{
	// std::cout << "AForm :: Method :: getName() called" << std::endl;
	return (name);
}

bool	AForm::getIsSigned() const
{
	// std::cout << "AForm :: Method :: getIsSigned() called" << std::endl;
	return (isSigned);
}

int	AForm::getSignGrade() const
{
	// std::cout << "AForm :: Method :: getSignGrade() called" << std::endl;
	return (signGrade);
}

int	AForm::getExcuteGrade() const
{
	// std::cout << "AForm :: Method :: getExcuteGrade() called" << std::endl;
	return (excuteGrade);
}

int	AForm::validGradeRange(const int grade) const
{
	std::cout << "AForm :: Method :: validGradeRange() called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return (grade);
}

void	AForm::validSignGrade(const int grade) const
{
	std::cout << "AForm :: Method :: validSignGrade() called" << std::endl;
	if (getSignGrade() < grade)
		throw GradeTooLowException();
}

void	AForm::validExcuteGrade(const int grade) const
{
	std::cout << "AForm :: Method :: validExcuteGrade() called" << std::endl;
	if (getExcuteGrade() < grade)
		throw GradeTooLowException();
}

void	AForm::validFormSigned() const
{
	std::cout << "AForm :: Method :: validFormSigned() called" << std::endl;
	if (!getIsSigned())
		throw FormNotSignedException();
}

void	AForm::beSigned(const Bureaucrat &br)
{
	std::cout << "AForm :: Method :: beSigned() called" << std::endl;
	validSignGrade(br.getGrade());
	isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "AForm :: exception :: Grade Too High Exception";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "AForm :: exception :: Grade Too Low Exception";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "AForm :: exception :: Form Not Signed Exception";
}

std::ostream&	operator<<(std::ostream &os, AForm &f)
{
	os << f.getName() << ", signGrade : " << f.getSignGrade() << ", excuteGrade : " << f.getExcuteGrade() << ", signed : " << (f.getIsSigned() ? "true" : "false") << "." << std::endl;
	return os;
}
