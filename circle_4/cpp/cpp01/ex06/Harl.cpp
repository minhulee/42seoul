/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:46:15 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 10:32:04 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl :: Constructor called.." << std::endl;
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
	std::cout << "Harl :: Destructor called.." << std::endl;
}

void	Harl::complain(std::string level)
{
	int	lv;

	for (int i = 0; i < 4; i++)
	{
		if (level == this->filter[i])
		{
			lv = i;
			break ;
		}
	}
	switch (lv)
	{
		case 0 : (this->*func[0])(); //fall-through
		case 1 : (this->*func[1])(); //fall-through
		case 2 : (this->*func[2])(); //fall-through
		case 3 : (this->*func[3])(); break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
};

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "This is the situation!, nothing has happened yet..." << std::endl;
};

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Oh..! There's a problem.. what should I do..?" << std::endl;
};

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "This is a warning!, but we can still fix it..." << std::endl;
};

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is an error! There is no answer..." << std::endl;
};
