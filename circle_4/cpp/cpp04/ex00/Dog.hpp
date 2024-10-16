/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:09:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/16 16:58:21 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./Animal.hpp"

class	Dog
: public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		const Dog	&operator=(const Dog &other);

		virtual void	makeSound() const;
};