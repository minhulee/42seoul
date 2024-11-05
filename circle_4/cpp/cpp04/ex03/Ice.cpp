/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:14:26 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:10:08 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"

Ice::Ice()
: AMateria("ice")
{
	std::cout << "Ice :: Default Constructor() called" << std::endl;
}

Ice::Ice(const Ice &other)
: AMateria(other.type)
{
	std::cout << "Ice :: Copy Constructor() called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice :: Destructor() called" << std:: endl;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Ice :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return (*this);
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "Ice :: Method :: use() called" << std::endl;
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}