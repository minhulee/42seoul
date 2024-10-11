/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:52:21 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 16:37:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
: name(name), hp(10), mp(10), damage(0)
{
	std::cout << "ClapTrap :: Constructor(name) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: name(other.name), hp(other.hp), mp(other.mp), damage(other.damage)
{
	std::cout << "ClapTrap :: Copy Constructor(&other) called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap :: Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		mp = other.mp;
		damage = other.damage;
	}
	return (*this);
}

bool	ClapTrap::canAction() const
{
	std::cout << "ClapTrap :: Method :: canAction() called" << std::endl;
	if (this->hp == 0)
		std::cout << "canAction() :: " << name << "'s hp is 0" << std::endl;
	else if (this->mp == 0)
		std::cout << "canAction() :: " << name << "'s mp is 0" << std::endl;
	else
		return (true);
	return (false);
}

const std::string	&ClapTrap::getName() const
{
	return (name);
}

const int	&ClapTrap::getDamage() const
{
	return (damage);
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap :: Method :: attack() called" << std::endl;
	if (!canAction())
	{
		std::cout << "attack() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	mp -= 1;
	std::cout << "attack() :: " << name << " attacks " << target << " , causing " << damage << " points of damage !"  << std::endl;
	std::cout << "attack() :: " << name << "'s hp is " << hp << ", mp is " << mp << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap :: Method :: takeDamage() called" << std::endl;
	if (hp == 0)
		std::cout << "takeDamage() :: " << name << "is already dead" << std::endl;
	else if (hp <= amount)
	{
		hp = 0;
		std::cout << "takeDamage() :: " << name << "is dead" << std::endl;
	}
	else
	{
		hp -= amount;
		std::cout << "takeDamage() :: " << name << "'s remaining hp is " << hp << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap :: Method :: beRepaired() called" << std::endl;
	if (!canAction())
	{
		std::cout << "beRepaired() :: " << name << "'s can't more Action" << std::endl;
		return ;
	}
	mp -= 1;
	hp += amount;
	std::cout << "beRepaired() :: " << name << "'s hp is " << hp << ", mp is " << mp << std::endl;
}