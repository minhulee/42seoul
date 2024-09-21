/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:33:38 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 14:18:09 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//void	check()
//{
//	system("leaks ZombieHoard");
//}

int	main(void)
{
	//atexit(check);
	// obj array create
	Zombie	*horde = zombieHorde(10, "horde");

	// each obj method call
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	
	// c++ is not provide basic error handle
	// So, we can choose using STL in std or adding error management in your class
	//horde[11].announce();
	//horde[12].announce();

	delete []horde;
	return (0);
}