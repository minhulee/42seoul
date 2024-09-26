/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:29:53 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 17:01:00 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	setHp(100);
	setMp(100);
	setDamage(30);
	std::cout << "FragTrap :: name constructor called !" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
: FragTrap(other.getName())
{
	setHp(other.getHp());
	setMp(other.getMp());
	setDamage(other.getDamage());
	std::cout << "FragTrap :: copy constructor called !" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap :: default destructor called !" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		setName(other.getName());
		setHp(other.getHp());
		setMp(other.getMp());
		setDamage(other.getDamage());
	}
	std::cout << "FragTrap :: copy assignment called !" << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "ScavTrap :: method guardGate() called !" << std::endl;
	std::cout << "ScavTrap :: " << getName() << " High Five !!! Guys !!" << std::endl;
}
