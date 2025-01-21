/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:58:13 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/21 18:15:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./Serializer.hpp"
#include <iostream>

// reinterpret_cast : 메모리 재해석을 의미한다.
// 코드의 가독성을 높이고, C 타입의 캐스팅은 C++에서 지원하는 경고를 받지 못한다.
int	main()
{
	Data		d;
	uintptr_t	raw = 0;

	d.i = 42;
	std::cout << "origin : " <<  &d << std::endl;
	raw = Serializer::serialize(&d);
	std::cout << "serialize : " << raw << std::endl;
	std::cout << "desirialize : " << Serializer::deserialize(raw) << std::endl;

	return (0);
}