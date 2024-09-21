/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/22 05:23:47 by minhulee         ###   ########seoul.kr  */
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
		
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;

		Fixed	operator+(const Fixed &other) const;
		Fixed	operator-(const Fixed &other) const;
		Fixed	operator*(const Fixed &other) const;
		Fixed	operator/(const Fixed &other) const;

		Fixed		&operator++(void);
		Fixed		&operator--(void);
		
		const Fixed	operator++(int);
		const Fixed	operator--(int);

		void	setRawBits(const int raw);
		int		getRawBits(void) const;

		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed	&min(Fixed &a, Fixed &b);

		static const Fixed	&max(const Fixed &a, const Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);

	private:
		int					value;
		static const int	rawBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
