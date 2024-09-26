/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 10:29:53 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
	setHp(100);
	setMp(50);
	setDamage(20);
	std::cout << "ScavTrap :: name constructor called !" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other.getName())
{
	setHp(other.getHp());
	setMp(other.getMp());
	setDamage(other.getDamage());
	std::cout << "ScavTrap :: copy constructor called !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap :: default destructor called !" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		setName(other.getName());
		setHp(other.getHp());
		setMp(other.getMp());
		setDamage(other.getDamage());
	}
	std::cout << "ScvaTrap :: copy assignment called !" << std::endl;
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap :: method guardGate() called !" << std::endl;
	std::cout << "ScavTrap :: " << getName() << " is Gate Keeper MODE !!!" << std::endl;
}
