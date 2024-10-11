/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:18 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 17:31:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ClapTrap	*b = new ScavTrap("b");
	ScavTrap	c(a);
	std::cout << std::endl;
	
	b->attack(a.getName());
	std::cout << std::endl;

	a.takeDamage(b->getDamage());
	std::cout << std::endl;
	
	for (int i = 0; i < 49; i++)
	{
		b->beRepaired(10);
		std::cout << std::endl;
	}
	
	b->beRepaired(10);
	std::cout << std::endl;

	*b = a;
	std::cout << std::endl;

	b->beRepaired(10);
	std::cout << std::endl;

	dynamic_cast<ScavTrap *>(b)->guardGate(); 
	std::cout << std::endl;
	
	delete(b);
	
	return (0);
}