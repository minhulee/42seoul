/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:50:45 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:27:02 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "./Cat.hpp"

Cat::Cat()
: Animal("Cat")
{
	std::cout << "Cat :: Default Constructor() called" << std::endl;
}


Cat::Cat(const Cat &other)
: Animal(other.type)
{
	std::cout << "Cat :: Copy Constructor(other) called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat :: Destructor() called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat :: Assignment Operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat :: Method :: makeSound() called" << std::endl;
	std::cout << "Meow ↑, Meow ↓" << std::endl;
}