/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:08 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/21 20:07:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <iostream>

// static_cast : c++ 언어 상에서 가능한 형변환이나, 자동변환을 지원하지 않는 경우
// 일반적으로, 해당 형변환을 통해 데이터에 손실(호환 불가)이 일어날 수 있는 경우를 의미한다.
// int -> char, float -> int, int -> char 등등...
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "input is invalid." << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
	
	return (0);
}