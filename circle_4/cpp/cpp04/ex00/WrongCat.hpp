/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:48:23 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/04 11:36:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./WrongAnimal.hpp"

class	WrongCat
: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		virtual ~WrongCat();

		const WrongCat	&operator=(const WrongCat &other);

	public:
		void	makeSound() const;
};