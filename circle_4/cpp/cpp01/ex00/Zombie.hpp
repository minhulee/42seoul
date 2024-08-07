/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:17:49 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 13:54:01 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie(const std::string &name);
		~Zombie();
		
		void		announce(void) const;
		
	private:
		std::string	name;
};

Zombie	*newZombie(const std::string &name);
void	randomChump(const std::string &name);
