/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:17:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 15:25:28 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();
		
		void				setName(const std::string &name);
		const std::string	&getName(void) const;
		
		void				announce(void) const;
		
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);
