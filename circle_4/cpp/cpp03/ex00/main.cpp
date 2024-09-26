/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:37:01 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/26 13:03:43 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int main(void)
{
	// ClapTrap	a; -> can't called default constructor
	ClapTrap	a("a");
	ClapTrap	b(a);
	ClapTrap	c("c");
	
	b = a;
	a.attack(c.getName());
	b.takeDamage(5);
	b.takeDamage(100);
	b.beRepaired(10);
	c.beRepaired(100);
	c = a;
	for (int i = 0; i < 10; i++)
		c.beRepaired(0);
	return 0;
}