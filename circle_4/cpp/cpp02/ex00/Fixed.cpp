/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 23:42:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << ":: Fixed :: default constructor called..." << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << ":: Fixed :: copy constructor called..." << std::endl;
	this->value = other.value;
}

Fixed	&Fixed::operator=(const Fixed &other)
{
	std::cout << ":: Fixed :: copy assignment constructor called..." << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << ":: Fixed :: default destructor called..." << std::endl;
}

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
