/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:27:26 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/14 19:32:07 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <climits>
#include <exception>
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>
#include "./ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {};
ScalarConverter::~ScalarConverter() {};

int	ScalarConverter::getN(std::string &input)
{
	int integerPart = static_cast<int>(stod(input));
	int digitCount = static_cast<int>(log10(fabs(integerPart))) + 1;
	return digitCount;
}

// isInf, isNan,
// 전반부 -> floor를 구현하라는게 아니라, leak -> main에서 명시적으로 delete
// 시험볼 때 main문을 내가 안적어 근데 spell 제거해라 이ㄹ
bool	ScalarConverter::convertJustChar(std::string &input)
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

char	ScalarConverter::stoc(std::string &input)
{
	if (stoi(input) < CHAR_MIN || CHAR_MAX < stoi(input))
		throw (OutOfRangeExc());
	return (static_cast<char>(stoi(input)));
}

int	ScalarConverter::stoi(std::string &input)
{
	std::stringstream	ss(input);
	long long			res;

	ss >> res;
	if (ss.fail())
		throw (ConvertFailExc());

	char	c;
	if (ss >> c && c != '.')
		throw (ConvertFailExc());

	if (res < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < res)
		throw (OutOfRangeExc());
	return (static_cast<int>(res));
}

float	ScalarConverter::stof(std::string &input)
{
	size_t				idx;

	idx = input.find('f');
	if (idx == input.size() - 1)
		input = input.substr(0, idx);
	
	std::stringstream	ss(input);
	double				res;
	
	ss >> res;
	if (ss.fail())
		throw (ConvertFailExc());
	if (res < std::numeric_limits<float>::lowest() || std::numeric_limits<float>::max() < res)
		throw (OutOfRangeExc());
	return (static_cast<float>(res));
}

double	ScalarConverter::stod(std::string &input)
{
	size_t				idx;

	idx = input.find('f');
	if (idx == input.size() - 1)
		input = input.substr(0, idx);
	
	std::stringstream	ss(input);
	double				res;
	
	ss >> res;
	if (ss.fail())
		throw (ConvertFailExc());
	if (res == std::numeric_limits<double>::infinity())
		throw (OutOfRangeExc());
	return (res);
}

void	ScalarConverter::convertChar(std::string &input)
{
	std::cout << "char: ";
	try
	{
		stof(input);
		if (isprint(stoc(input)))
			std::cout << "'" << stoc(input) << "'";
		else
			std::cout << "Non displayable";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible :: " << e.what();
		return ;
	}
}

void	ScalarConverter::convertInt(std::string &input)
{	
	std::cout << "int: ";
	try
	{
		stof(input);
		std::cout << stoi(input) << std::endl;;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible :: " << e.what();
	}
}

void	ScalarConverter::convertFloat(std::string &input)
{
	std::cout << "float: ";
	try
	{
		if (getN(input) < 7)
		{
			std::cout << std::setprecision(getN(input) + 7) << stof(input);
			if (static_cast<int>(stof(input)) == stof(input))
				std::cout << ".0f";
			else
				std::cout << "f";
		}
		else
			std::cout << stof(input);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible :: " << e.what();
	}
}

void	ScalarConverter::convertDouble(std::string &input)
{
	std::cout << "double: ";
	try
	{
		if (getN(input) < 7)
		{
			std::cout << std::setprecision(getN(input) + 16) << stod(input);
			if (static_cast<int>(stod(input)) == stod(input))
				std::cout << ".0";
		}
		else
			std::cout << stod(input);
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible :: " << e.what() << std::endl;
	}
}

// inf, nan
void	ScalarConverter::convert(std::string input)
{
	ScalarConverter	converter;
	if (input.find("nan") == 0 && input.size() == 3)
	{
		std::ostringstream	ss;
		ss << "char : impossible\n";
		ss << "int : impossible\n";
		ss << "float : nanf\n";
		ss << "double : nan\n";
		std::cout << ss.str() << std::endl;
	}
	else if ((input.find("inf") == 0 && input.size() == 3) || (input.find("+inf") == 0 && input.size() == 4))
	{
		std::ostringstream	ss;
		ss << "char : impossible\n";
		ss << "int : impossible\n";
		ss << "float : +inff\n";
		ss << "double : +inf\n";
		std::cout << ss.str() << std::endl;
	}
	else if (input.find("-inf") == 0 && input.size() == 4)
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
		if (converter.convertJustChar(input))
			return ;
		converter.convertChar(input);
		converter.convertInt(input);
		converter.convertFloat(input);
		converter.convertDouble(input);
	}
}

const char	*ScalarConverter::ConvertFailExc::what() const throw()
{
	return ("ScalarConverter :: Exception :: Convert Fail.\n");
}

const char	*ScalarConverter::OutOfRangeExc::what() const throw()
{
	return ("ScalarConverter :: Exception :: Out of Range.\n");
}
