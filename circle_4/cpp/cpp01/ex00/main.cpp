/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:33:38 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 14:05:03 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//void	check()
//{
//	system("leaks Zombie");
//}

int	main(void)
{
	// atexit(check);
	// heap obj -> destructor must be called
	{
		Zombie	*zombie = newZombie("Foo");
		zombie->announce();
		delete zombie;

		std::cout << "\n\n";
	}

	// randomChump(temp obj)
	{
		randomChump("temp");
		std::cout << "out scope\n";
		std::cout << "\n\n";
	}

	// named obj -> call scope valid
	{
		Zombie	z = Zombie("Boo");
		z.announce();
	}
	return (0);
}