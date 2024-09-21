/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:46:15 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 17:09:54 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl :: Constructor called..\n" << std::endl;
	this->filter[0] = "DEBUG";
	this->filter[1] = "INFO";
	this->filter[2] = "WARNING";
	this->filter[3] = "ERROR";
	this->func[0]	= &Harl::debug;
	this->func[1]	= &Harl::info;
	this->func[2]	= &Harl::warning;
	this->func[3]	= &Harl::error;
};

Harl::~Harl(void)
{
	std::cout << "Harl :: Destructor called..\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == filter[i])
			(this->*func[i])();
	}
};

void	Harl::debug(void)
{
	std::cout << "DEBUG :: This is the situation!, nothing has happened yet...\n" << std::endl;
};

void	Harl::info(void)
{
	std::cout << "INFO :: Oh..! There's a problem.. what should I do..?\n" << std::endl;
};

void	Harl::warning(void)
{
	std::cout << "WARNING :: This is a warning!, but we can still fix it...\n" << std::endl;
};

void	Harl::error(void)
{
	std::cout << "ERROR :: This is an error! There is no answer...\n" << std::endl;
};
