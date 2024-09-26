/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:05:24 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 17:05:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string &name)
: name(name), hp(10), mp(10), damage(0)
{
	std::cout << "ClapTrap :: constructor called ! " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
: name(other.name), hp(other.hp), mp(other.mp), damage(other.damage)
{
	std::cout << "ClapTrap :: copy constructor called !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap :: destructor called !" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		name = other.name;
		hp = other.hp;
		mp = other.mp;
		damage = other.damage;
		std::cout << "ClapTrap :: copy assignment called !" << std::endl;
	}
	return *this;
}

const std::string	&ClapTrap::getName() const
{
	std::cout << "ClapTrap :: method getName() called" << std::endl;
	return name;
}

const unsigned int	&ClapTrap::getHp() const
{
	std::cout << "ClapTrap :: method getHp() called" << std::endl;
	return hp;
}

const unsigned int	&ClapTrap::getMp() const
{
	std::cout << "ClapTrap :: method getMp() called" << std::endl;
	return mp;
}

const unsigned int	&ClapTrap::getDamage() const
{
	std::cout << "ClapTrap :: method getDamage() called" << std::endl;
	return damage;
}

void	ClapTrap::setName(const std::string &name_)
{
	std::cout << "ClapTrap :: method setName() called" << std::endl;
	name = name_;
}

void	ClapTrap::setHp(const unsigned int amount)
{
	std::cout << "ClapTrap :: method setHp() called" << std::endl;
	hp = amount;
}

void	ClapTrap::setMp(const unsigned int amount)
{
	std::cout << "ClapTrap :: method setMp() called" << std::endl;
	mp = amount;
}

void	ClapTrap::setDamage(const unsigned int amount)
{
	std::cout << "ClapTrap :: method setDamage() called" << std::endl;
	damage = amount;
}

bool	ClapTrap::isCanAction()
{
	std::cout << "ClapTrap :: method isCanAction() called" << std::endl;
	if (hp == 0)
	{
		std::cout << name << " is out of hp" << std::endl;
		return false;
	}
	if (mp == 0)
	{
		std::cout << name << " is out of mp" << std::endl;
		return false;
	}
	return true;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap :: method attack() called" << std::endl;
	if (isCanAction())
	{
		mp--;
		std::cout  << name << " attacks " << target << ", causing " << damage << " points of damage !" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap :: method takeDamage() called" << std::endl;
	if (!isCanAction())
		return ;
	else if (hp <= amount)
	{
		hp = 0;
		std::cout << name << " is dead..." << std::endl;
	}
	else
	{
		hp -= amount;
		std::cout << name << "'s hp is " << hp << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap :: method beRepaired() called" << std::endl;
	if (isCanAction())
	{
		mp--;
		hp += amount;
		std::cout << name << " repaired itself !" << std::endl;
		std::cout << name << "'s hp is " << hp << std::endl;
	}
}
