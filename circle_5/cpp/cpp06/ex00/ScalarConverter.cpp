/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:27:26 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/13 23:00:13 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <sstream>
#include <cmath>
#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

std::string	ScalarConverter::isInf(std::string &input)
{
	if (input.find("inf") == 0)
		return ("+inf");
	else if (input.find("-inf") == 0)
		return ("-inf");
	return ("");
}

std::string	ScalarConverter::isNan(std::string &input)
{
	if (input.find("nan") == 0)
		return ("nan");
	return ("");
}

bool	ScalarConverter::isNumber(std::string &input)
{
	std::stringstream	ss(input);
	int					target;
	char				rest;

	ss >> target;
	if (ss.eof() && !ss.fail())
		return (true);
	else
		ss >> rest;
	return (rest == '.');
}

int	ScalarConverter::strToInt(std::string &input)
{
	std::stringstream	ss(input);
	int					i;

	ss >> i;
	return (i);
}

float	ScalarConverter::strToFloat(std::string &input)
{
	size_t				idx;

	idx = input.find('f');
	if (idx == input.size() - 1)
		input = input.substr(0, idx);
	
	std::stringstream	ss(input);
	float				f;
	
	ss >> f;
	return (f);
}

double	ScalarConverter::strToDouble(std::string &input)
{
	size_t				idx;

	idx = input.find('f');
	if (idx == input.size() - 1)
		input = input.substr(0, idx);
	
	std::stringstream	ss(input);
	double				d;
	
	ss >> d;
	return (d);
}

// 문자열로 들어올 때 and 숫자로 들어올 떄
// 32 ~ 126

void	ScalarConverter::convertChar(std::string &input)
{
	std::ostringstream	os;
	int					target;
	
	os << "char: ";
	if (isNumber(input))
	{
		target = strToFloat(input);
		if (target == 0)
			os << "impossible";
		else if (isprint(target))
			os << "'" << static_cast<char>(target) << "'";
		else
			os << "Non displayable";
	}
	else if (input.size() == 1)
		os << "'" << input[0] << "'";
	else
		os << "impossible";
	std::cout << os.str() << std::endl;
}

// 문자열 -> 숫자로
// 숫자 -> 그대로
void	ScalarConverter::convertInt(std::string &input)
{
	std::ostringstream	os;
	int					target;

	os << "int: ";
	if (isNumber(input))
	{
		target = strToFloat(input);
		if (target == 0)
			os << "impossible";
		else
			os << strToInt(input);
	}
	else
		os << static_cast<int>(input[0]);
	std::cout << os.str() << std::endl;
}

void	ScalarConverter::convertFloat(std::string &input)
{
	std::ostringstream	os;
	float				target;

	os << "float: ";
	os << isNan(input) << isInf(input);
	if (isNumber(input))
	{
		target = strToFloat(input);
		if (target == 0.0)
			os << "impossible";
		else
		{
			os << target;
			if (floor(strToFloat(input)) == strToFloat(input))
				os << ".0f";
			else
				os << "f";
		}
	}
	else
		os << static_cast<int>(input[0]);
	std::cout << os.str() << std::endl;
}

void	ScalarConverter::convertDouble(std::string &input)
{
	std::ostringstream	os;

	os << "double: ";
	if (isNumber(input))
		os << strToDouble(input);
	else
		os << static_cast<int>(input[0]);
	std::cout << os.str() << std::endl;
}

// inf, nan
void	ScalarConverter::convert(std::string input)
{
	ScalarConverter	converter;
	if (input.find("nan") == 0)
	{
		std::ostringstream	ss;
		ss << "char : impossible\n";
		ss << "int : impossible\n";
		ss << "float : nanf\n";
		ss << "double : nan\n";
		std::cout << ss.str() << std::endl;
	}
	else if (input.find("inf") == 0 || input.find("+inf") == 0)
	{
		std::ostringstream	ss;
		ss << "char : impossible\n";
		ss << "int : impossible\n";
		ss << "float : +inff\n";
		ss << "double : +inf\n";
		std::cout << ss.str() << std::endl;
	}
	else if (input.find("-inf") == 0)
	{
		std::ostringstream	ss;
		ss << "char : impossible\n";
		ss << "int : impossible\n";
		ss << "float : -inff\n";
		ss << "double : -inf\n";
		std::cout << ss.str() << std::endl;
	}
	else
	{
		converter.convertChar(input);
		converter.convertInt(input);
		converter.convertFloat(input);
		converter.convertDouble(input);
	}
}

