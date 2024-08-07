/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:21:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 13:54:11 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name)
{
	std::cout << name << " Zombie created..." << std::endl;
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << " Zombie killed..." << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
