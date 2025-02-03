/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:32:02 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/03 14:07:55 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>

int main()
{
	Span				span(10001);
	std::vector<int>	vec;

	for (int i = 0; i < 10000; i++)
		vec.push_back(i);
	
	span.addNumber(vec.begin(), vec.end());

	std::cout << "shortest Span : " << span.shortestSpan() << std::endl;
	std::cout << "longest Span : " << span.longestSpan() << std::endl;

	// FullSpanException
	try
	{
		span.addNumber(1);
	}
	catch (std::exception &e)
	{
		std:: cout << e.what() << std::endl;
	}

	// EmptySpanException
	try
	{
		Span(2).shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}