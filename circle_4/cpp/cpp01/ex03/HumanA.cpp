/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:30:29 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/08 14:54:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : weapon(weapon)
{
	this->name = name;
	this->weapon = weapon;
	std::cout << "HumanA :: " << this->name << " create..." << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA :: " << name << " kill...\n" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType()
			  << std::endl;
}