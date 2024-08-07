/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:33:38 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 13:54:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	// heap obj -> destructor must be called
	Zombie	*zombie = newZombie("Foo");
	zombie->announce();
	delete zombie;

	std::cout << "\n\n";

	// randomChump(temp obj)
	randomChump("temp");

	std::cout << "\n\n";
	
	// named obj -> call scope valid
	Zombie	z = Zombie("Boo");
	z.announce();
}