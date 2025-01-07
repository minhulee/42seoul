/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:48:57 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/07 13:26:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const int grade)
: name(name)
{
	std::cout << "Bureaucrat :: Constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
: name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat :: Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat :: Destructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat :: Assignment Operator called" << std::endl;
	if (this != &other)
		setGrade(grade);
	return (*this);
}

void	Bureaucrat::validGrade(int grade)
{
	std::cout << "Bureaucrat :: Method :: validGrade() called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::setGrade(int grade)
{
	std::cout << "Bureaucrat :: Method :: setGrade() called" << std::endl;
	validGrade(grade);
	this->grade = grade;
}

std::string	Bureaucrat::getName() const
{
	//std::cout << "Bureaucrat :: Method :: getName() called" << std::endl;
	return (name);
};

int	Bureaucrat::getGrade() const
{
	//std::cout << "Bureaucrat :: Method :: getGrade() called" << std::endl;
	return (grade);
};

void	Bureaucrat::incrementGrade()
{
	std::cout << "Bureaucrat :: Method :: incrementGrade() called" << std::endl;
	setGrade(grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Bureaucrat :: Method :: decrementGrade() called" << std::endl;
	setGrade(grade + 1);
}

std::ostream&	operator<<(std::ostream& os, Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat :: exception :: Grade Too High Exception";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat :: exception :: Grade Too Low Exception";
}