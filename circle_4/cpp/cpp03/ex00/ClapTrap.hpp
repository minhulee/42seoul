/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 10:59:28 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 17:02:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>

class	ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &other);

		const std::string	&getName() const;
		const unsigned int	&getHp() const;
		const unsigned int	&getMp() const;
		const unsigned int	&getDamage() const;

		void		setName(const std::string &name_);
		void		setHp(const unsigned int amount);
		void		setMp(const unsigned int amount);
		void		setDamage(const unsigned int amount);
		
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	private:
		ClapTrap();

		bool		isCanAction();
		
		std::string		name;
		unsigned int	hp;
		unsigned int	mp;
		unsigned int	damage;
};
