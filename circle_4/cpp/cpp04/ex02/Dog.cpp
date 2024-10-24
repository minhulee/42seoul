/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/21 16:21:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog()
: Animal("Dog")
{
	std::cout << "Dog :: Default Constructor() called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &other)
: Animal(other.type)
{
	std::cout << "Dog :: Copy Constructor(type) called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog :: Destructor() called" << std::endl;
	delete brain;
}

const Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain();
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog :: Method :: makeSound() called" << std::endl;
	std::cout << "Bark, Bark !" << std::endl;
}