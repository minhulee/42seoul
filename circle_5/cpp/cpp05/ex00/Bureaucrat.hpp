/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:31:00 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/11 16:20:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP

# include <exception>
# include <string>
# include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat		&operator=(const Bureaucrat &other);

		const std::string	&getName() const;
		const int			&getGrade() const;

		void				incrementGrade();
		void				decrementGrade();

	private:
		Bureaucrat();
		void	setGrade(int grade);
	
	private:
		const std::string	name;
		int					grade;

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