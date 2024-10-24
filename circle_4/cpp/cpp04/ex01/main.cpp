/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:03:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/24 19:28:32 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

// void	check()
// {
// 	system("leaks Brain");
// }

int main(void)
{
	// atexit(check);
	
	int	ea = 4;
	Animal	*animals[ea];

	for (int i = 0; i < ea; i++)
	{
		if (i < ea / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;
	
	for (int i = 0; i < ea; i++)
		delete animals[i];

	std::cout << std::endl;

	Cat	a = Cat();
	a.openMind();

	std::cout << std::endl;
	
	Cat b = a;
	b.openMind();
	
	std::cout << std::endl;
	
	b = a;
	b.openMind();

	std::cout << std::endl;
	return (0);
}