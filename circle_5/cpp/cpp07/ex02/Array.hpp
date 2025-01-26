/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:21:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/27 03:28:58 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ARRAY_HPP
 #define	ARRAY_HPP

#include <exception>

template<typename T>
class	Array
{
	/* OCF */
	public:
		Array();
		Array(const unsigned int n);
		Array(const Array &other);
		
		~Array();

		Array	&operator=(const Array &other);

	/* Operator Overload*/
	public:
		T	&operator[](const unsigned int n);

	/* Method */
	public:
		unsigned int	size() const;

	/* Member */
	private:
		unsigned int	len;
		T				*arr;

	/* Exception*/
	public:
		class	OutOfRangeException : public	std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#include "Array.tpp"

#endif