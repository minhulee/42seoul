/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:58:54 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/16 16:44:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
 #define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class	RobotomyRequestForm : public AForm
{
	/* OCF */
	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
	
	private:
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);
		
	/* Methods */
	public:
		std::string	getTarget() 					const;
		void		excute(const Bureaucrat &br)	const;

	/* Members */
	private:
		std::string	target;
};

#endif