/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:21:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/06 08:31:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Character.hpp"
#include "AMateria.hpp"

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
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const Character &other)
: name(other.name)
{
	std::cout << "Character :: Copy Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.slot[i] != NULL)
			slot[i] = other.slot[i]->clone();
		else
			slot[i] = NULL;
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

Character	&Character::operator=(const Character &other)
{
	std::cout << "Character :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (slot[i] != NULL)
				delete slot[i];
			slot[i] = other.slot[i]->clone();
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
	if (!m)
		return ;
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
	if ((idx < 0 || 3 < idx) || !slot[idx])
		return ;
	slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	std::cout << "Character :: Method :: use() called" << std::endl;
	if ((idx < 0 || 3 < idx) || !slot[idx])
		return ;
	slot[idx]->use(target);
}

AMateria	*Character::exportMateria(int idx)
{
	std::cout << "Character :: Method :: exportMateria" << std::endl;
	if ((idx < 0 || 3 < idx) || !slot[idx])
		return (NULL);
	return (slot[idx]);
}