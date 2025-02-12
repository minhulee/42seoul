/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:44:27 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/12 17:38:50 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <cmath>

#define INVALID_INPUT -1

int	getJacobsthalNum(int n)
{
	int	prev = 0;
	int jacobsthalNum = 0;
	for (int i = 0; jacobsthalNum > n; i++)
	{
		prev = jacobsthalNum;
		jacobsthalNum = (pow(2, i + 1) + pow(-1, i)) / 3;
	}
	return (prev);
}

void	testPrint(std::deque<int *>::iterator it, std::deque<int *>::iterator end)
{
	int	n = 1;

	// std::cout << "test print" << std::endl;
	while (it != end)
	{
		std::cout << "Pairs " << n << " : [" << (*it)[0] << "] [" << (*it)[1] << "]" << std::endl;
		it++;
		n++;
	}
}

int	invalidInput(char *s)
{
	double	res;
	char	*eptr;

	res = std::strtod(s, &eptr);

	if (*eptr != '\0')
		return (INVALID_INPUT);

	if (res < 0)
		return (INVALID_INPUT);

	if (res != static_cast<int>(res))
		return (INVALID_INPUT);

	return (res);
}

std::deque<int>	PmergeMe::inputToDq(char **av)
{
	std::deque<int>	dq;
	
	for (int i = 0; av[i] != NULL; i++)
	{
		int	target = invalidInput(av[i]);

		if (target == INVALID_INPUT)
			throw (InvalidInput());
		dq.push_back(target);
	}

	return (dq);
}

// void	PmergeMe::makePair(std::deque<int *> &pair, const std::deque<int> &dq)
// {
// 	std::deque<int>::const_iterator	it = dq.begin();
	
// 	while (it != dq.end())
// 	{
// 		std::deque<int>::const_iterator	next = it;
// 		next++;

// 		int	*target = new int[2];
// 		target[0] = *it < *next ? *next : *it;
// 		target[1] = *it < *next ? *it : *next;
// 		pair.push_back(target);
// 		it++;
// 		if (it == dq.end())
// 			break ;
// 		it++;
// 	}
// 	if (it != dq.end())
// 	{
// 		int	*target = new int[2];
// 		target[0] = *it;
// 		target[1] = 0;
// 		pair.push_back(target);
// 	}
// }

int	dqlen(std::deque<int *>::const_iterator it, std::deque<int *>::const_iterator end)
{
	size_t	len = 0;

	while (it != end)
	{
		len++;
		it++;
	}
	return (len);
}

void	dqswap(std::deque<int *>::iterator left, std::deque<int *>::iterator right)
{
	int	*tmp = *left;

	*left = *right;
	*right = tmp;
}

void	PmergeMe::mergeInsertionSort(std::deque<int *>::iterator it, std::deque<int *>::iterator end)
{
	size_t	len = dqlen(it, end);
	std::deque<int *>::iterator middle = it;
	std::advance(middle, len / 2);

	if (len < 2)
		return ;

	std::cout << "swap---------" << std::endl;

	for (size_t i = 0; i < len / 2; i++)
	{
		if (*(it + i)[0] < *(middle + i)[0])
		{
			dqswap(it + i, middle + i);
			std::cout << "swap : " << *(it + i)[0] << " | " << *(middle + i)[0] << std::endl;
		}
	}
	
	testPrint(it, end);
	mergeInsertionSort(it, middle);

	std::cout << "insertion------" << std::endl;
	testPrint(it, end);

	for (int i = getJacobsthalNum(len); i > 0; i--)
	{
		if (*(it + i)[1])
		{
			
		}
	}
}

void	dqClear(std::deque<int *>dq)
{
	std::deque<int *>::iterator itr = dq.begin();

	while (itr != dq.end())
		delete[] *(itr++);
}

void	PmergeMe::run(char **av)
{
	std::deque<int *>	deque;
	std::list<int *>	list;

	try
	{
		makePair(deque, inputToDq(av + 1));
		std::cout << "init ! -------------" << std::endl;
		testPrint(deque.begin(), deque.end());
		std::cout << std::endl << std::endl;
		mergeInsertionSort(deque.begin(), deque.end());
		// binery search
		dqClear(deque);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}	
};

const char	*PmergeMe::InvalidInput::what() const throw()
{
	return ("Error: invalid input.");
}
