/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:36:46 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:29:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	/* OCF */
	public:
		Form(const std::string name, const int signGrade, const int excuteGrade);
		Form(const Form &other);
		~Form();

	private:
		Form		&operator=(const Form &other); // Don't do that, = delete in C++11
	
	/* Methods*/
	public:
		std::string			getName() 			const;
		bool				getIsSigned() 		const;
		int					getSignGrade() 		const;
		int					getExcuteGrade() 	const;

		void				beSigned(const Bureaucrat &br);
	
	private:
		int					validGradeRange(const int grade) const;
		void				validSignGrade(const int grade) const;

	/* Members */
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			excuteGrade;
	
	/* Exception */
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &os, Form &f);

#endif