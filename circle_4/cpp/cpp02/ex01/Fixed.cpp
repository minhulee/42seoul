/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/22 04:15:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

/* constructor */
Fixed::Fixed(void)
: value(0)
{
	std::cout << ":: Fixed :: default constructor called..." << std::endl;
}

Fixed::Fixed(const int integer)
: value(integer << rawBits)
{
	std::cout << ":: Fixed :: const int constructor called..." << std::endl;
}

Fixed::Fixed(const float point)
: value(roundf(point * (1 << rawBits)))
{
	std::cout << ":: Fixed :: const float constructor called..." << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << ":: Fixed :: copy constructor called..." << std::endl;
	*this = other;
}

/* operator */
Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << ":: Fixed :: copy assignment constructor called..." << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

/* destructor*/
Fixed::~Fixed()
{
	std::cout << ":: Fixed :: default destructor called..." << std::endl;
}

/* method */
void	Fixed::setRawBits(const int raw)
{
	std::cout << ":: Fixed :: member func -> setRawBits called..." << std::endl;
	this->value = raw;
};

int	Fixed::getRawBits(void) const
{
	std::cout << ":: Fixed :: member func -> getRawBits called..." << std::endl;
	return this->value;
};

float	Fixed::toFloat(void) const
{
	// std::cout << ":: Fixed :: member func -> toFloat called..." << std::endl;
	return (float)value / (float)(1 << rawBits);
}

int	Fixed::toInt(void) const
{
	// std::cout << ":: Fixed :: member func -> toInt called..." << std::endl;
	return this->value >> rawBits;
}
