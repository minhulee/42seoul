/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:27:26 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/22 11:31:36 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <climits>
#include <limits>
#include <iomanip>

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

int	getN(std::string &input)
{
	int integerPart = static_cast<int>(atof(input.c_str()));
	int digitCount = static_cast<int>(log10(fabs(integerPart))) + 1;
	return digitCount;
}

bool	invalidFormat(std::string &input)
{
	size_t				idx;

	if (input == "inf" || input == "+inf" || input == "-inf" || input == "inff")
		return (true);
	
	idx = input.find('f');
	if (idx == input.size() - 1)
		input = input.substr(0, idx);

	std::stringstream	ss(input);
	double				res;
	
	ss >> res;
	if (ss.fail())
		return (false);
	return (true);
}

bool	convertJustChar(std::string &input)
{
	if (input.size() != 1)
		return (false);

	char	c = input[0];
	if (!isprint(c) || ('0' <= c && c <= '9'))
		return (false);

	std::cout << "char: " << "'" << c << "'\n"
			  << "int: " << static_cast<int>(c) << "\n"
			  << "float: " << static_cast<float>(c) << ".0f\n"
			  << "double: " << static_cast<double>(c) << ".0\n";

	return (true);
}

void	ScalarConverter::convert(std::string input)
{
	if (convertJustChar(input))
		return ;

	if (!invalidFormat(input))
	{
		std::cout << "input is invalid." << std::endl;
		return ;
	}

	double	res = atof(input.c_str());

	// char
	std::cout << "char : ";
	if (res < CHAR_MIN || CHAR_MAX < res)
		std::cout << "impossible : out of range !" << std::endl;
	else if (!isprint(static_cast<int>(res)))
		std::cout << "not printable !" << std::endl;
	else
		std::cout << "'" << static_cast<char>(res) << "'" << std::endl;

	// int
	std::cout << "int : ";
	if (input == "nan")
		std::cout << "impossible : nan !" << std::endl;
	else if (res < INT_MIN || INT_MAX < res)
		std::cout << "impossible : out of range !" << std::endl;
	else
		std::cout << static_cast<int>(res) << std::endl;

	// float
	std::cout << "float : ";
	if (getN(input) < 7)
	{
		if (static_cast<int>(res) == static_cast<float>(res))
			std::cout << static_cast<float>(res) << ".0f" << std::endl;
		else
			std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(res) << "f" << std::endl;
	}
	else
		std::cout  << static_cast<float>(res) << std::endl;

	// double
	std::cout << "double : ";
	if (getN(input) < 7)
	{
		if (static_cast<int>(res) == res)
			std::cout << res << ".0" << std::endl;
		else
			std::cout << std::setprecision(std::numeric_limits<double>::digits10) << res << std::endl;
	}
	else
		std::cout << res << std::endl;
}
