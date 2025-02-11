/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:24:00 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/11 17:10:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
 #define	RPN_HPP

#include <stack>
#include <exception>

class	RPN
{
	/* user can acess only this func */
	public:
		static void	run(char *av);

	/* encapsulates the main funcs */
	private:
		static bool	calculate(std::stack<int, std::vector<int> > &, char c);
		static int	pop(std::stack<int, std::vector<int> > &);
	
	/* exceptions */
	private:
		class	InvalidFormat : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	DivideByZero : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif