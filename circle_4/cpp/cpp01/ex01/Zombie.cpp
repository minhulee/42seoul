/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:21:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 14:08:10 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << name << "Unnamed Zombie created..." << std::endl;
	this->name = "Unnamed";
}

Zombie::Zombie(const std::string &name)
{
	std::cout << name << " Zombie created..." << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " Zombie killed..." << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	this->name = name;
}

const std::string	&Zombie::getName(void) const
{
	return this->name;
}

void	Zombie::announce(void) const
{
	std::cout << this << std::endl;
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
