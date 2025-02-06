/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:45:38 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/06 17:50:47 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "BitcoinExchange.hpp"

// 1. data | value
// 2. Year-Month-Day
// 3. 0 ~ 1000, int or float
// 4. 입력 날짜가 없는 경우, 가까운 날짜의 데이터 사용 - 미래 데이터 불가
int	main(int ac, char **av)
{
	// invalid input
	if (ac < 2)
	{
		std::cerr << "btc :: invalid input (too many args)" << std::endl;
		return (1);
	}
	
	BitcoinExchange::run(av[1]);

	return (0);
}