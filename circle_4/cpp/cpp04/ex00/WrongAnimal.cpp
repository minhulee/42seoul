/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:36:33 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:27:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: type("<None>")
{
	std::cout << "WrongAnimal :: Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
: type(type)
{
	std::cout << "WrongAnimal :: Constructor(type) called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
: type(other.type)
{
	std::cout << "WrongAnimal :: Copy Constructor() called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal :: Destructor() called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal :: Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

const std::string &WrongAnimal::getType() const
{
	std::cout << "WrongAnimal :: Method :: getType() called" << std::endl;
	return (type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal :: Method :: makeSound() called" << std::endl;
	std::cout << "type is <None>, what ????" << std::endl;
}