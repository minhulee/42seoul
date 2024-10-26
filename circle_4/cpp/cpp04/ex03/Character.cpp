/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:21:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/26 22:24:41 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"

Character::Character()
{
	std::cout << "Character :: Default Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const std::string &name)
: name(name)
{
	std::cout << "Character :: Constructor(name) called" << std::endl;

}

Character::Character(const Character &other)
: name(other.name)
{
	std::cout << "Character :: Copy Constructor() called" << std::endl;
	name = other.name;
	for (int i = 0; i < 4; i++)
	{
		delete slot[i];
		slot[i] = other.slot[i];
	}
}

Character::~Character()
{
	std::cout << "Character :: Destructer() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] != NULL)
			delete slot[i];
	}
}

const Character	&Character::operator=(const Character &other)
{
	std::cout << "Character :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			delete slot[i];
			slot[i] = other.slot[i];
		}
	}
	return (*this);
}

const std::string	&Character::getName() const
{
	std::cout << "Character :: Method :: getName() called" << std::endl;
	return (name);
}

void	Character::equip(AMateria *m)
{
	std::cout << "Character :: Method :: equip() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	std::cout << "Character :: Method :: unequip() called" << std::endl;
	if (idx < 0 || 3 < idx)
		return ;
	slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || 3 < idx)
		return ;
	slot[idx]->use(target);
}