/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:54 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/14 21:52:06 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
 #define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	/* OCF */
	public:
		PresidentialPardonForm(const std::string target); // default
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
	
	private:
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &other);
		
	/* Methods */
	public:
		std::string	getTarget() 					const;
		void		excute(const Bureaucrat &br)	const;

	/* Members*/
	private:
		std::string	target;

	/* exception */
};

#endif