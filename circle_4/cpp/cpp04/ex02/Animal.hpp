/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:33:10 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:28:11 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &other);
		virtual	~Animal();

		Animal	&operator=(const Animal &other);

		const std::string	&getType() const;
		
		virtual void		makeSound() const = 0;

	protected:
		std::string	type;
};