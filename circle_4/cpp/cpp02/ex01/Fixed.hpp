/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/22 04:11:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma	once

#include <iostream>

class   Fixed
{
	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float point);
		Fixed(const Fixed &other);
		~Fixed();

		Fixed	&operator=(const Fixed &other);

		void	setRawBits(const int raw);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					value;
		static const int	rawBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
