/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:50:45 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:28:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "./Cat.hpp"

Cat::Cat()
: Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat :: Default Constructor() called" << std::endl;
}


Cat::Cat(const Cat &other)
: Animal(other.type), brain(new Brain(*other.brain))
{
	std::cout << "Cat :: Copy Constructor(other) called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat :: Destructor() called" << std::endl;
	delete brain;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat :: Assignment Operator called" << std::endl;
	if (this != &other)
	{
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
		// *brain = *other.brain;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat :: Method :: makeSound() called" << std::endl;
	std::cout << "Meow ↑, Meow ↓" << std::endl;
}

void	Cat::openMind() const
{
	std::cout << "Cat :: Method :: openMind() called" << std::endl;
	std::cout << "my brain is " << brain << std::endl;
	// for (int i = 0; i < 100; i++)
	// 	std::cout << brain->getIdea(i) << std::endl;
}