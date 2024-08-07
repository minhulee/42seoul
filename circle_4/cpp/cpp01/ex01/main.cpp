/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:33:38 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 15:22:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	// obj array create
	Zombie	*horde = zombieHorde(10, "horde");

	// each obj method call
	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}
	
	// c++ is not provide basic error handle
	// So, we can choose using STL in std or adding error management in your class
	horde[11].announce();
	horde[12].announce();

	delete []horde;
}