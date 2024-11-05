/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:36:33 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/04 11:57:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal()
: type("<None>")
{
	std::cout << "Animal :: Default Constructor called" << std::endl;
}

Animal::Animal(const std::string &type)
: type(type)
{
	std::cout << "Animal :: Constructor(type) called" << std::endl;
}

Animal::Animal(const Animal &other)
: type(other.type)
{
	std::cout << "Animal :: Copy Constructor() called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal :: Destructor() called" << std::endl;
}

const Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal :: Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

const std::string &Animal::getType() const
{
	std::cout << "Animal :: Method :: getType() called" << std::endl;
	return (type);
}
