/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:22:47 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/01 23:27:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> vector(10);
	std::vector<int>::iterator it;
	
	for (size_t i = 0; i < 10; i++)
		vector.push_back(i);

	try
	{
		it = easyfind(vector, 6);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Can't find." << std::endl;
	}

	try
	{
		it = easyfind(vector, 11);
		std::cout << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Can't find." << std::endl;
	}

	return (0);
}