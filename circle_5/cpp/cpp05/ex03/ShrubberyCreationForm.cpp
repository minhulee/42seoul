/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:04:21 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 16:44:15 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << "ShrubberyCreationForm :: Constructor() called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
: AForm(other), target(other.target)
{
	std::cout << "ShrubberyCreationForm :: Copy Constructor() called" << std::endl;;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm :: Destructor() called" << std::endl ;
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (target);
}

void	ShrubberyCreationForm::excute(const Bureaucrat &br) const
{
	std::cout << "ShrubberyCreationForm :: Methods :: excute() called" << std::endl;
	validFormSigned();
	validExcuteGrade(br.getGrade());
	std::ofstream	out((getTarget() + std::string("_shrubbery")).c_str());
	if (!out)
		throw FailCreateOutFile();
	out	 << "---------------------------------------\n"
		 << "              v .   ._, |_  .,         \n"
		 << "       `-._\\/  .  \\ /    |/_         \n"
		 << "            \\  _\\, y | \\//          \n"
		 << "      _\\_.___\\, \\/ -.\\||           \n"
		 << "       `7-,--.`._||  / / ,             \n"
		 << "        /'     `-. `./ / |/_.'         \n"
		 << "                 |    |//              \n"
		 << "                 |_    /               \n"
		 << "                 |-   |                \n"
		 << "                 |   =|                \n"
		 << "                 |    |                \n"
		 << "----------------/ ,  . \\---------------\n"
		 << " target : " << getTarget() << std::endl;
	out.close();
}

const char*	ShrubberyCreationForm::FailCreateOutFile::what() const throw()
{
	return "Bureaucrat :: exception :: Fail Create Ouf File Exception";
}
