/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:31:00 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 14:23:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <iostream>

class	Form;

class	Bureaucrat
{
	/* OCF */
	public:
		Bureaucrat(const std::string &name, const int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &other);

	/* Methods */
	public:
		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade();
		void		decrementGrade();

		void		signForm(Form &f);

	private:
		int			validGrade(int grade);
		void		setGrade(int grade);
	
	/* Members */
	private:
		const std::string	name;
		int					grade; // 1 ~ 150 grade

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

std::ostream	&operator<<(std::ostream& os, Bureaucrat& rhs);

#endif