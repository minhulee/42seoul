/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:18 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 16:41:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("a");
	ClapTrap	*b = new ClapTrap("b");

	std::cout << std::endl;
	a.attack(b->getName());
	std::cout << std::endl;
	b->takeDamage(a.getDamage());
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
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
	
	delete(b);
	
	return (0);
}