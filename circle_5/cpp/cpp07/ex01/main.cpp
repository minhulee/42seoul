/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:37:36 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/27 10:42:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

int main()
{
	int		arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char	arr2[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	float	arr3[5] = {0.1, 0.2, 0.3, 0.4, 0.5};

	::iter(arr, 10, ::test<int>);
	::iter(arr2, 6, ::test<char>);
	::iter(arr3, 5, test<float>);
	
	std::cout << "arr : ";
	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << (i < 9 ? " " : "");
	std::cout << std::endl;

	std::cout << "arr2 : ";
	for (int i = 0; i < 6; i++)
		std::cout << arr2[i] << (i < 5 ? " " : "");
	std::cout << std::endl;

	std::cout << "arr3 : ";
	for (int i = 0; i < 5; i++)
		std::cout << arr2[i] << (i < 4 ? " " : "");
	std::cout << std::endl;
	return (0);
}