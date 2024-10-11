/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:59:28 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 16:37:21 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &other);

		const std::string	&getName()		const;
		const int			&getDamage()	const;

		void				attack(const std::string &target);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

	private:
		ClapTrap();

		bool		canAction() const;
		
		std::string	name;
		int			hp;
		int			mp;
		int			damage;
};
