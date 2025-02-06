/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:59:42 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/06 18:01:03 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <string>

void	BitcoinExchange::run(std::string path)
{
	std::map<std::string, int>	map;
	std::ifstream				input;

	(void)path;
	try
	{
		loadData(map);
		loadInput(input, path);
		inputExchangeData(map, input);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	BitcoinExchange::lineToMap(std::map<std::string, int> &map, const char *seperator, std::string line)
{
	size_t		n = line.find(seperator);

	if (n == std::string::npos)
		throw InvalidFormat();
	
	std::string	key = line.substr(0, n);
	char		*eptr;
	double		value = std::strtod(line.substr(n + 1, line.size() - 1).c_str(), &eptr);

	if (*eptr != '\0')
		throw StrtodConvertFailed();
	
	map[key] = value;
}

// data.csv open, 별도의 예외처리 x
void	BitcoinExchange::loadData(std::map<std::string, int> &map)
{
	std::ifstream	data("./data.csv");

	if (!data.is_open())
		throw DataOpenFailed();

	std::string	line;
	std::getline(data, line);
	
	if (line != "date,exchange_rate")
		throw InvalidFormat();

	try
	{
		while (std::getline(data, line))
			lineToMap(map, ",", line);
	}
	catch (std::exception &e)
	{
		throw ;
	}
	data.close();
}

// input.txt open, 별도의 예외처리 x
void	BitcoinExchange::loadInput(std::ifstream &input, std::string path)
{
	input.open(path);

	if (!input.is_open())
		throw InputOpenFailed();

	std::string	line;
	std::getline(input, line);

	if (line != "date | value")
		throw InvalidFormat();
}

void	BitcoinExchange::validData(std::string line)
{
	
}

// input * data의 결과 출력 및 유효성 검사
void	BitcoinExchange::inputExchangeData(std::map<std::string, int> &map, std::ifstream &input)
{
	std::string	line;
	

	input.close();
}

const char	*BitcoinExchange::DataOpenFailed::what() const throw()
{
	return ("exception :: faild opening data.csv :: ");
}

const char	*BitcoinExchange::InputOpenFailed::what() const throw()
{
	return ("exception :: faild opening input.txt :: ");
}

const char	*BitcoinExchange::InvalidFormat::what() const throw()
{
	return ("exception :: invalid format :: ");
}

const char	*BitcoinExchange::StrtodConvertFailed::what() const throw()
{
	return ("exception :: failed strtod() func (not integer or float) :: ");
}