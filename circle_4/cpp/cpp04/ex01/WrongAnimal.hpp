/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:33:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 16:43:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		virtual	~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal &other);

		const std::string	&getType() const;
		
		void		makeSound() const;

	protected:
		std::string	type;
};