/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:23:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/25 12:26:34 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type)
: type(type)
{
	std::cout << "AMateria :: Constructor(type) called" << std::endl;
}

const std::string	&AMateria::getType() const
{
	std::cout << "AMateria :: Method :: getType() called" << std::endl;
	return (type);
}