/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:53:33 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 17:04:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
: ClapTrap(name)
{
	std::cout << "ScavTrap :: Constructor(name) called" << std::endl;
	hp = 100;
	mp = 50;
	damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other.name)
{
	std::cout << "ScavTrap :: Copy Constructor(&other) called" << std::endl;
	hp = other.hp;
	mp = other.mp;
	damage = other.damage;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap :: Destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		mp = other.mp;
		damage = other.damage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap :: Method :: attack() called" << std::endl;
	if (!canAction())
	{
		std::cout << "attack() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	mp -= 1;
	std::cout << "attack() :: " << name << " attacks " << target << " , causing " << damage << " points of damage !"  << std::endl;
	std::cout << "attack() :: " << name << "'s hp is " << hp << ", mp is " << mp << std::endl;
}

void	ScavTrap::guardGate() const
{
	std::cout << "ScavTrap :: Method :: guardGate() called" << std::endl;
	if (!canAction())
	{
		std::cout << "guardGate() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	std :: cout << "guardGate() :: " << name << " is Gate Keeper Mode Activated !" << std::endl;
}