/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:40:17 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/13 12:52:19 by minhulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << ":: Fixed :: default constructor called...\n" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << ":: Fixed :: copy constructor called...\n" << std::endl;
    this->value = other.value;
}

Fixed   &Fixed::operator=(const Fixed &other)
{
    std::cout << ":: Fixed :: copy assignment constructor called...\n" << std::endl;
    if (this != &other)
        this->value = other.value;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << ":: Fixed :: default destructor called...\n" << std::endl;
}

void    Fixed::setRawBits(const int raw)
{
    std::cout << ":: Fixed :: member func -> setRawBits called...\n" << std::endl;
    this->value = raw;
};

int Fixed::getRawBits(void) const
{
    std::cout << ":: Fixed :: member func -> getRawBits called...\n" << std::endl;
    return this->value;
};
