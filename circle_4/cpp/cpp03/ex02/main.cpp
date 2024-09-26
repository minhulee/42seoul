/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:09:44 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 17:08:35 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

int	main(void)
{
	FragTrap	a("a");
	FragTrap	a_(a);
	FragTrap	c("c");

	a.attack(c.getName());
	c.takeDamage(a.getDamage());
	for (int i = 0; i < 100; i++)
		c.beRepaired(0);
	c.beRepaired(0);
	c.highFivesGuys();
	return 0;
}