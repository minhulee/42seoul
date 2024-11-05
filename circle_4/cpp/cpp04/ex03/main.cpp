/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:17:52 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:25:11 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Ice.hpp"
#include "./Cure.hpp"
#include "./MateriaSource.hpp"
#include "./Character.hpp"

void	check()
{
	system("leaks AMATERIA");
}

// MateriaSource()
int	main(void)
{
	atexit(check);

	IMateriaSource	*src = new MateriaSource();
	
	std::cout << std::endl;
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl;

	IMateriaSource	*src2 = new MateriaSource(dynamic_cast<MateriaSource &>(*src));

	std::cout << std::endl;
	
	ICharacter	*me = new Character("me");
	
	std::cout << std::endl;
	
	AMateria	*tmp1 = src->createMateria("ice");
	AMateria	*tmp2 = src2->createMateria("cure");
	
	std::cout << std::endl;
	
	me->equip(tmp1);
	me->equip(tmp2);

	std::cout << std::endl;
	
	ICharacter* bob = new Character("bob");

	std::cout << std::endl;

	ICharacter	*c = new Character(dynamic_cast<Character &>(*me));

	c->use(0, *bob);
	c->use(1, *bob);

	std::cout << std::endl;
	
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	bob->use(0, *me);
	bob->use(1, *me);

	std::cout << std::endl;
	
	me->unequip(0);
	me->unequip(1);
	
	delete bob;
	delete me;
	delete c;
	delete src;
	delete src2;
	delete tmp1;
	delete tmp2;

	return (0);
}