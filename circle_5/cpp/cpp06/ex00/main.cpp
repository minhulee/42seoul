/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:08 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/13 22:11:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	ScalarConverter::convert(av[1]);
	
	return (0);
}