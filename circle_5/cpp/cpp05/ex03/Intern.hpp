/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:51:52 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 18:50:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
 #define INTERN_HPP

#include "./AForm.hpp"

class	Intern
{
	/* OCF */
	public:
		Intern();
		~Intern();

	private:
		// no make sence, = delete in c++11
		Intern(const Intern &other);
		Intern	*operator=(const Intern &other);
	
	/* Methods */
	private:
		AForm	*makeShrubberyCreationForm(const std::string target);
		AForm	*makeRobotomyRequestForm(const std::string target);
		AForm	*makePresidentialPardonForm(const std::string target);

	public:
		AForm	*makeForm(std::string type, const std::string target);

	/* Members */
	private:
		std::string	list[3];
		AForm		*(Intern::*creators[3])(const std::string target);

	/* exceptions*/
	private:
		class	InvalidFormException : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

#endif