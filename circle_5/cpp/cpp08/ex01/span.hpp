/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 00:29:51 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/02 01:16:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SPAN_HPP
 #define	SPAN_HPP

class	Span
{
	/* OCF */
	public:
		Span(const unsigned int);
		Span(const Span &other);

		Span	&operator=(const Span &other);
		
		~Span();

	/* Method */

	/* Member */
}

#endif