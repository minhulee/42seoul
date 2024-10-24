/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:09:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/24 19:08:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./Animal.hpp"
# include "./Brain.hpp"

class	Dog
: public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		virtual ~Dog();

		const Dog	&operator=(const Dog &other);

		virtual void	makeSound() const;
		void			openMind() const;

	private:
		Brain	*brain;
};