/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:01:51 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/03 14:07:29 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

Span::Span(const unsigned int length)
: length(length)
{
	std::cout << "Span :: Constructor() called" << std::endl;
}

Span::Span(const Span &other)
: length(other.length), set(other.set)
{
	std::cout << "Span :: Copy Constructor() called" << std::endl;
}

Span	&Span::operator=(const Span &other)
{
	std::cout << "Span :: operator=() called" << std::endl;
	if (this != &other)
	{
		length = other.length;
		set = other.set;
	}
	return (*this);
}

Span::~Span()
{
	std::cout << "Span :: Destructor() called" << std::endl;
}

void	Span::addNumber(int n)
{
	if (set.size() == length)
		throw FullSpanException();
	set.insert(n);
}

unsigned int	Span::shortestSpan()
{	
	if (set.size() < 2)
		throw EmptySpanException();
	
	int	gap = std::abs(*set.end() - *set.begin());
	std::set<int>::iterator	next_itr = set.begin();
	std::advance(next_itr, 1);
	for (std::set<int>::iterator itr = set.begin(); next_itr != set.end(); itr++, next_itr++)
	{
		int	cur_gap = std::abs(*next_itr - *itr);
		if (gap > cur_gap)
			gap = cur_gap;
	}
	return (gap);
}

//min = -200, max = 100 -> 300
unsigned int	Span::longestSpan()
{
	if (set.size() < 2)
		throw EmptySpanException();
	
	return (*set.end() - *set.begin());
}

const char	*Span::InvalidLengthException::what() const throw()
{
	return ("Span :: Exception :: invalid length.");
}

const char	*Span::FullSpanException::what() const throw()
{
	return ("Span :: Exception :: span's set is full.");
}

const char	*Span::EmptySpanException::what() const throw()
{
	return ("Span :: Exception :: what ? your set is insufficient.");
}