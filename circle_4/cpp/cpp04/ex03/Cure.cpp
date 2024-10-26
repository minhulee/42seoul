/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:14:26 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/26 17:20:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Cure.hpp"

Cure::Cure()
: AMateria("Cure")
{
	std::cout << "Cure :: Default Constructor() called" << std::endl;
}

Cure::Cure(const Cure &other)
: AMateria(other.type)
{
	std::cout << "Cure :: Copy Constructor() called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure :: Destructor() called" << std:: endl;
}

const Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

void	use(ICharacter &target)
{
	std::cout << "Cure :: Method :: use() called" << std::endl;
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}