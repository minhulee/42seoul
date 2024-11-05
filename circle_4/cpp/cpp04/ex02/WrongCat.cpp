/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:50:45 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:29:08 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "./WrongCat.hpp"

WrongCat::WrongCat()
: WrongAnimal("WrongCat")
{
	std::cout << "WrongCat :: Default Constructor() called" << std::endl;
}


WrongCat::WrongCat(const WrongCat &other)
: WrongAnimal(other.type)
{
	std::cout << "WrongCat :: Copy Constructor(other) called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat :: Destructor() called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat :: Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat :: Method :: makeSound() called" << std::endl;
	std::cout << "Meow ↑, Meow ↓" << std::endl;
}