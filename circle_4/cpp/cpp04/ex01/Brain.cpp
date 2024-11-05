/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:56:57 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 16:42:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain :: Default Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "I have no idea !";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain :: Copy Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain :: Destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::setIdea(const std::string &idea, int idx)
{
	std::cout << "Brain :: Method :: setIdea() called" << std::endl;
	ideas[idx] = idea;
}

const std::string	&Brain::getIdea(int idx)
{
	return (ideas[idx]);
}
