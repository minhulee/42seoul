/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:28:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 14:48:04 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANB_HPP
# define	HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();

		void	attack(void) const;
		void	setWeapon(Weapon *weapon);

	private:
		std::string	name;
		Weapon		*weapon;
};

# endif
