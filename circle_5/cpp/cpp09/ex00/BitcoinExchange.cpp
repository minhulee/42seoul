/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:59:42 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/09 14:39:14 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

#include <iostream>
#include <string>
#include <fstream> // -> ifstream OBJ
#include <sstream> // -> iss OBJ
#include <cfloat> // -> FLT_LIMITS
#include <cstdlib> // -> strtod()

#define ERROR -1
#define INVALID_DATE -1
#define INVALID_FORMAT -2
#define NOT_POSITIVE -3
#define TOO_LARGE -4
#define NO_DATA -5

void	BitcoinExchange::run(std::string path)
{
	std::map<std::string, float>	mData;

	try
	{
		loadData(mData);
		inputExchangeData(mData, path);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// yyyy-mm-dd 유효성 검사
std::string	BitcoinExchange::validDate(const std::string line)
{
	if (line.length() != 10)
		return ("");
	
	std::istringstream	iss(line);
	int year, month, day;
	char s1, s2;

	iss >> year >> s1 >> month >> s2 >> day;

	if (iss.fail() || s1 != '-' || s2 != '-')
		return ("");

	if (month > 12)
		return ("");

	int	days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// 윤년 계산
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		days[1] = 29;

	if (days[month - 1] < day)
		return ("");

	return (line);
}

float	BitcoinExchange::validValue(const std::string line)
{
	if (line.length() == 0 || line[0] == ' ')
		return (INVALID_FORMAT);
	
	double	res;
	char	*eptr;

	res = std::strtod(line.c_str(), &eptr);
	
	if (*eptr != '\0')
		return (INVALID_FORMAT);

	if (res < 0)
		return (NOT_POSITIVE);

	if (FLT_MAX < res)
		return (TOO_LARGE);

	return (res);
}

void	BitcoinExchange::lineToMap(std::map<std::string, float> &map, const char *seperator, std::string line)
{
	size_t	n = line.find(seperator);

	if (n == std::string::npos)
		throw InvalidFormat();
	
	std::string	key = validDate(line.substr(0, n));

	if (key == "")
		throw InvalidDate();

	float	value = validValue(line.substr(n + 1, line.length()));

	if (value < 0)
		throw InvalidValue();
	
	map[key] = value;
}

// data.csv open, 별도의 예외처리 x
void	BitcoinExchange::loadData(std::map<std::string, float> &mData)
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
			lineToMap(mData, ",", line);
	}
	catch (std::exception &e)
	{
		throw ;
	}
	
	data.close();
}

float	searchValue(std::string date, std::map<std::string, float> &mData)
{
	std::map<std::string, float>::iterator	itr = mData.lower_bound(date);
	if (itr == mData.begin())
		return (NO_DATA);

	if (itr == mData.end() || itr->first != date)
		itr--;

	return (itr->second);
}

void	eprint(int mode, size_t n, std::string line)
{
	std::string	date = line.substr(0, n);
	std::string value = line.substr(n + 3, line.length());

	switch (mode)
	{
		case INVALID_DATE:		std::cerr << "Error: bad input => [" << date << "]" << std::endl;				break ;
		case INVALID_FORMAT:	std::cerr << "Error: invlid format. => [" << value << "]" << std::endl;			break ;
		case NOT_POSITIVE:		std::cerr << "Error: not a positive number. => [" << value << "]" << std::endl;	break ;
		case TOO_LARGE:			std::cerr << "Error: too large number => [" << value << "]" << std::endl;		break ;
		case NO_DATA:			std::cerr << "Error: no data. [" << date << "]" << std::endl;					break ;
	}
}

// input * data의 결과 출력 및 유효성 검사
void	BitcoinExchange::inputExchangeData(std::map<std::string, float> &mData, std::string path)
{
	std::ifstream	input(path.c_str());
	
	if (!input.is_open())
		throw InputOpenFailed();

	std::string	line;
	std::getline(input, line);

	if (line != "date | value")
		throw InvalidFormat();

	while (std::getline(input, line))
	{
		size_t	n = line.find(" | ");
		
		std::string	date = validDate(line.substr(0, n));
		float value = validValue(line.substr(n + 3, line.length()));
		float mValue = searchValue(date, mData);
	
		if (n == std::string::npos)
			eprint(INVALID_FORMAT, n, line);
		else if (date == "")
			eprint(INVALID_DATE, n, line);
		else if (value <= ERROR)	
			eprint(value, n, line);
		else if (value > 1000)
			eprint(TOO_LARGE, n, line);
		else if (mValue < ERROR)
			eprint(mValue, n, line);
		else
			std::cout << date << " => " << value << " = " << value * mValue << std::endl;
	}

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

const char	*BitcoinExchange::InvalidDate::what() const throw()
{
	return ("exception :: invalid data :: ");
}

const char	*BitcoinExchange::InvalidValue::what() const throw()
{
	return ("exception :: invalid value :: ");
}