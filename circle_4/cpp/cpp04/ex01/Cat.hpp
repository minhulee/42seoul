/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:48:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/24 19:08:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./Animal.hpp"
# include "./Brain.hpp"

class	Cat
: public Animal
{
	public:
		Cat();
		Cat(const Cat &other);
		virtual ~Cat();

		const Cat	&operator=(const Cat &other);

		virtual void	makeSound() const;
		void			openMind() const;

	private:
		Brain	*brain;
};