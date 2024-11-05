/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:53:02 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:28:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog()
: Animal("Dog"), brain(new Brain())
{
	std::cout << "Dog :: Default Constructor() called" << std::endl;
}

Dog::Dog(const Dog &other)
: Animal(other.type), brain(new Brain(*other.brain))
{
	std::cout << "Dog :: Copy Constructor(type) called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog :: Destructor() called" << std::endl;
	delete brain;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain();
		// *brain = *other.brain;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog :: Method :: makeSound() called" << std::endl;
	std::cout << "Bark, Bark !" << std::endl;
}

void	Dog::openMind() const
{
	std::cout << "Dog :: Method :: openMind() called" << std::endl;
	std::cout << "my brain is " << brain << std::endl;
	// for (int i = 0; i < 100; i++)
	// 	std::cout << brain->getIdea(i) << std::endl;
}