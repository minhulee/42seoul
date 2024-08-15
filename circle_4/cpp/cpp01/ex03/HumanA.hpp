/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:28:05 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/08 08:51:28 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANA_HPP
# define	HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(const std::string &name, Weapon &wapon);
		~HumanA();

		void	attack(void);

	private:
		std::string	name;
		Weapon		&weapon;
};

# endif
