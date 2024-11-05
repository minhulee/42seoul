/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:03:42 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/04 11:38:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"
#include "./Cat.hpp"
#include "./Dog.hpp"
#include "./WrongAnimal.hpp"
#include "./WrongCat.hpp"

//void	check()
//{
//	system("leaks Animal");
//}

int main(void)
{
	//atexit(check);
	{
		Animal	animal;
		Animal	*cat = new Cat();
		Animal	*dog = new Dog();

		std::cout << std::endl;

		std::cout << animal.getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		std::cout << dog->getType() << std::endl;

		std::cout << std::endl;

		animal.makeSound();
		cat->makeSound();
		dog->makeSound();

		std::cout << std::endl;
		
		delete(cat);
		delete(dog);
	}
	{
		std::cout << std::endl;

		WrongAnimal	*tmp = new WrongCat();

		std::cout << std::endl;
		
		tmp->makeSound();

		std::cout << std::endl;
		
		delete(tmp);
	}
	return (0);
}