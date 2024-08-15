/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:48:30 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/08 09:39:16 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include "HumanB.hpp"

int	main(void)
{
	{
		Weapon	weapon = Weapon("absolute spear");
		HumanA	bob("Bob", weapon);
		bob.attack();
		weapon.setType("trash");
		bob.attack();
	}
	{
		Weapon	weapon = Weapon("absolute shield");
		HumanB	cris("cirs");
		cris.attack();
		cris.setWeapon(&weapon);
		cris.attack();
		weapon.setType("just shield");
		cris.attack();
	}
}