/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:06 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ScavTrap	a_(a);
	ScavTrap	c("c");

	a.attack(c.getName());
	c.takeDamage(a.getDamage());
	for (int i = 0; i < 50; i++)
		c.beRepaired(0);
	c.beRepaired(0);
	c.guardGate();
	return 0;
}