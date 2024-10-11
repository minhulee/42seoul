/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:23:35 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 17:27:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
: ClapTrap(name)
{
	std::cout << "FragTrap :: Constructor(name) called" << std::endl;
	hp = 100;
	mp = 100;
	damage = 30;
}

FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other.name)
{
	std::cout << "FragTrap :: Copy Constructor(&other) called" << std::endl;
	hp = other.hp;
	mp = other.mp;
	damage = other.damage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap :: Destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
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

void	FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap :: Method :: attack() called" << std::endl;
	if (!canAction())
	{
		std::cout << "attack() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	mp -= 1;
	std::cout << "attack() :: " << name << " attacks " << target << " , causing " << damage << " points of damage !"  << std::endl;
	std::cout << "attack() :: " << name << "'s hp is " << hp << ", mp is " << mp << std::endl;
}

void	FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap :: Method :: highFivesGuys() called" << std::endl;
	if (!canAction())
	{
		std::cout << "highFivesGuys() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	std :: cout << "highFivesGuys() :: " << name << " : Guys ! give me Five ! " << std::endl;
}