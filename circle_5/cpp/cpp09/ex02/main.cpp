/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:01:04 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/12 11:02:19 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Error: invalid input" << std::endl;
		return (1);
	}
	PmergeMe::run(av);
	return (0);
}