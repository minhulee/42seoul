/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/22 05:18:44 by minhulee         ###   ########seoul.kr  */
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
Fixed	&Fixed::operator=(const Fixed &other) // 이미 한번 초기화된 객체를 다른 객체로 덮을때
{
	std::cout << ":: Fixed :: copy assignment operator called..." << std::endl;
	if (this != &other)
		this->value = other.value;
	return *this;
}

bool	Fixed::operator>(const Fixed &other) const
{
	if (value > other.value)
		return true;
	return false;
}

bool	Fixed::operator<(const Fixed &other) const
{
	if (value < other.value)
		return true;
	return false;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	if (value >= other.value)
		return true;
	return false;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	if (value <= other.value)
		return true;
	return false;
}

bool	Fixed::operator==(const Fixed &other) const
{
	if (value == other.value)
		return true;
	return false;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	if (value != other.value)
		return true;
	return false;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	value++;
	return *this;
}

Fixed	&Fixed::operator--(void)
{
	value--;
	return *this;
}

const Fixed	Fixed::operator++(int)
{
	const Fixed	temp = *this;
	value++;
	return temp;
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	temp = *this;
	value--;
	return temp;
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

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

/* ostream operator */
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
