/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:07:16 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/26 22:26:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource :: Default Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
		source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
: MateriaSource()
{
	std::cout << "MateriaSource :: Copy Constructor() called" << std::endl;
	for (int i = 0; i < 4; i++)
		source[i] = other.source[i];
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

const MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << "MateriaSource :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			source[i] = other.source[i];
		}
	}
}
