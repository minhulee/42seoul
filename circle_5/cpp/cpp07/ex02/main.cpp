/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:47:35 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/27 03:38:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define len 5

int	main()
{
	Array<int>	arr(len);
	std::cout << "arr  : " << &arr[0] << std::endl;
	for (unsigned int i = 0; i < len; i++)
		arr[i] = i + 1;

	Array<int>	arr2(3);
	std::cout << "arr2 : " << &arr2[0] << std::endl;
	std::cout << "init !" << std::endl;
	for (unsigned int i = 0; i < 3; i++)
		std::cout << arr2[i] << std::endl;

	std::cout << std::endl;
	
	arr2 = arr;
	arr2[4] = 99;
	std::cout << "copy !" << std::endl;
	for (unsigned int i = 0; i < len; i++)
		std::cout << arr2[i] << std::endl;

	std::cout << std::endl;
	
	std::cout << "origin !" << std::endl;
	for (unsigned int i = 0; i < len; i++)
		std::cout << arr[i] << std::endl;

	try
	{
		arr[6];
	}
	catch (std::exception &e)
	{
		std::cout << "Exception :: " << e.what() << std::endl;
	}

	return (0);
}