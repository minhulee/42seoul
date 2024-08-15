/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:22:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/08 08:54:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	std::cout << "Weapon create...\n" << std::endl;
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroy...\n" << std::endl;
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}

const std::string	&Weapon::getType(void) const
{
	return type;
}
