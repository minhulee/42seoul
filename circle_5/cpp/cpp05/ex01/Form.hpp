/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:36:46 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/07 13:22:22 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "./Bureaucrat.hpp"

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
		int					getExceuteGrade() 	const;

		void				beSigned(Bureaucrat &br);
	
	private:
		int					validGrade(const int grade) const;

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
