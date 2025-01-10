/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:54 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 17:16:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
 #define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	/* OCF */
	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
	
	private:
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
		
	/* Methods */
	public:
		std::string	getTarget() 					const;
		void		excute(const Bureaucrat &br)	const;

	/* Members */
	private:
		std::string	target;

	/* exception */
	class FailCreateOutFile : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

#endif