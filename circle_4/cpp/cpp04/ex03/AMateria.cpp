/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:23:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 12:19:44 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
: type(type)
{
	std::cout << "AMateria :: Constructor(type) called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria :: Destructor() called" << std::endl;
}

const std::string	&AMateria::getType() const
{
	std::cout << "AMateria :: Method :: getType() called" << std::endl;
	return (type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria :: Method :: use() called" << std::endl;
	std::cout << target.getName() << std::endl;
}