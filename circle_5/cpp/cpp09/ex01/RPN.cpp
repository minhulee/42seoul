/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:56:44 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/11 17:13:49 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <vector>

int	RPN::pop(std::stack<int, std::vector<int> > &stack)
{
	int	res;
	res = stack.top();
	stack.pop();
	return (res);
}

bool	RPN::calculate(std::stack<int, std::vector<int> > &stack, char c)
{
	if (std::isdigit(static_cast<unsigned int>(c)))
	{
		stack.push(c - '0');
		return (true);
	}

	if (stack.size() < 2)
		throw (InvalidFormat());

	int	a = pop(stack), b = pop(stack);
	switch (c)
	{
		case '+' : stack.push(b + a); break ;
		case '-' : stack.push(b - a); break ;
		case '*' : stack.push(b * a); break ;
		case '/' : a != 0 ? stack.push(b / a) : throw (DivideByZero()); break ;
		default  : throw (InvalidFormat());
	}
	return (true);
}

void	RPN::run(char *av)
{
	std::stack<int, std::vector<int> >	stack;
	
	try
	{
		for (int i = 0; av[i] != '\0'; i++)
		{
			if (i % 2 == 1 && av[i] == ' ')
				continue ;
			
			calculate(stack, av[i]);
		}
		
		if (stack.size() != 1)
			std::cerr << "Error: not enough operator" << std::endl;
		else
			std::cout << pop(stack) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char	*RPN::InvalidFormat::what() const throw()
{
	return ("Error: invalid format.");
}

const char	*RPN::DivideByZero::what() const throw()
{
	return ("Error: can't divide by zero");
}
