/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:03:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 16:48:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"

//void	check()
//{
//	system("leaks Brain");
//}

int main(void)
{
	//atexit(check);
	
	int	ea = 2;
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
	
	Cat	src, dst;

	std::cout << std::endl;

	src.openMind();

	std::cout << std::endl;

	dst.openMind();

	std::cout << std::endl;
	
	src = dst;

	std::cout << std::endl;
	
	src.openMind();
	
	std::cout << std::endl;

	Cat tmp = src;

	std::cout << std::endl;

	tmp.openMind();

	std::cout << std::endl;
	return (0);
}