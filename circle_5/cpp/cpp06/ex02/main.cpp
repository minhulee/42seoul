/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:49:26 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/22 12:02:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Base.hpp"
#include "./A.hpp"
#include "./B.hpp"
#include "./C.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

Base	*generate()
{
	Base	*res;

	switch (std::rand() % 3)
	{
		case 0:
			res = new A(); break;
		case 1:
			res = new B(); break;
		case 2:
			res = new C(); break;
	}
	return (res);
};

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "*p's type is 'A' !" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "*p's type is 'B' !" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "*p's type is 'C !" << std::endl;
	else
		std::cout << "I don't know *p's TYPE .." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "*p's type is 'A' !" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "*p's type is 'B' !" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "*p's type is 'C' !" << std::endl;
		return ;
	}
	catch (std::exception &e) {}
	std::cout << "I don't know *p's TYPE .." << std::endl;
}

// 런타임에서 타입을 확인함으로써, 상속 관계에서 다운 캐스팅에 사용하는 연산자
// -> vtable을 통해 상속 관계를 확인함으로, 가상 함수가 반드시 필요하다~
int	main(void)
{
	std::srand(time(0));
	Base *tmp = generate();

	identify(tmp);
	identify(*tmp);
	delete tmp;
	return (0);
}