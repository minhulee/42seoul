/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:21:43 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/26 22:35:47 by minhulee         ###   ########seoul.kr  */
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
		Array(unsigned int n);
		Array(const Array &other);
		~Array();

		Array	&operator=(const Array &other);

	/* Operator Overload*/
	public:
		T		&operator[](int n);

	/* Method */
	public:
		int		size() const;

	/* Member */
	private:
		T					*arr;
		const unsigned int	len;

	/* Exception*/
	private:
		class	OutOfRangeException : protected	std::exception
		{
			public:
				const char	*what() throw();
		};
};

#endif