/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:07:16 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:12:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource :: Default Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << "MateriaSource :: Copy Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other.source[i] != NULL)
			source[i] = other.source[i]->clone();
		else
			source[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource :: Destructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source[i] != NULL)
			delete source[i];
	}
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (source[i] != NULL)
				delete source[i];
			source[i] = other.source[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "MateriaSource :: learnMateria() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source[i] == NULL)
		{
			std::cout << i << "'s slot learn " << m->getType() << " !" << std::endl;
			source[i] = m;
			break ;
		}
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	std::cout << "MateriaSource :: createMateria() called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source[i] == NULL)
			break ;
		if (source[i]->getType() == type)
			return (source[i]->clone());
	}
	std::cout << type << " is not learned" << std::endl;
	return (static_cast<AMateria *>(NULL));
}
