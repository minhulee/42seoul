/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:48:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:26:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./Animal.hpp"

class	Cat
: public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		virtual ~Cat();

		Cat	&operator=(const Cat &other);

		virtual void	makeSound() const;
};