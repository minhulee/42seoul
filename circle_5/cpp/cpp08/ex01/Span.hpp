/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:29:51 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/03 14:08:08 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
 #define	SPAN_HPP

#include <set>

class	Span
{
	/* OCF */
	public:
		Span(const unsigned int length);
		Span(const Span &other);

		Span	&operator=(const Span &other);
		
		~Span();

	/* Method */
	public:
		void	addNumber(int n);
		
		template <typename itr>
		void	addNumber(itr begin, itr end)
		{
			while (begin != end)
				addNumber(*(begin++));
		}
		
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	/* Member */
	private:
		unsigned int	length;
		std::set<int>	set;

	/* exception */
	public:
		class	InvalidLengthException : public std::exception
		{
			public :
				const char	*what() const throw();
		};

		class	FullSpanException : public std::exception
		{
			public :
				const char	*what() const throw();
		};

		class	EmptySpanException : public std::exception
		{
			public :
				const char	*what() const throw();
		};
};

#endif