/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:33:00 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/07 18:49:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = std::string("HI THIS IS BRAIN");
	std::string	str2 = "HI THIS IS BRAIN!";
	
	std::string	*stringPTR = &str;
	
	// must be given valid obj
	// ref variable can't be reinitial
	std::string	&stringREF = str;

	// this is not re initial, just change value of str
	stringREF = str2;

	std::cout << str << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}