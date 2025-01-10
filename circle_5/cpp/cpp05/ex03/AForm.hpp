/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:36:46 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 18:00:45 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

# include <string>
# include <exception>
# include <iostream>

class Bureaucrat;

class AForm
{
	/* OCF */
	public:
		AForm(const std::string name, const int signGrade, const int excuteGrade);
		AForm(const AForm &other);
		virtual ~AForm();

	private:
		AForm		&operator=(const AForm &other); // Don't do that, = delete in C++11
	
	/* Methods*/
	public:
		std::string			getName() 			const;
		bool				getIsSigned() 		const;
		int					getSignGrade() 		const;
		int					getExcuteGrade() 	const;

		void				beSigned(const Bureaucrat &br);
		virtual void		excute(const Bureaucrat &br) 	const = 0;
	
	protected:
		int					validGradeRange(const int grade)	const;
		void				validSignGrade(const int grade)		const;
		void				validExcuteGrade(const int grade)	const;
		void				validFormSigned() 					const;

	/* Members */
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			excuteGrade;
	
	/* Exception */
	protected:
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw();
		};
		
		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw();
		};

		class	FormNotSignedException : public std::exception {
			public:
				const char	*what() const throw();
		};
};

std::ostream&	operator<<(std::ostream &os, AForm &f);

#endif