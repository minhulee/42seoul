/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:44:27 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/13 16:54:26 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <cmath>

#define INVALID_INPUT -1

size_t PmergeMe::findInsertPoint(int value, std::deque<int*>& firstHalf) {
    size_t index = 0;
    for (std::deque<int*>::iterator it = firstHalf.begin(); it != firstHalf.end(); ++it, ++index) {
        if (value < (*it)[0])
            return index;
    }
    return firstHalf.size();
}

void	testPrint(std::deque<int>::iterator it, std::deque<int>::iterator end)
{
	// std::cout << "test print" << std::endl;
	std::cout << "elements : ";
	while (it != end)
	{
		std::cout <<  *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	testPrint(std::deque<int *>::iterator it, std::deque<int *>::iterator end)
{
	// std::cout << "test print" << std::endl;
	int	n = 1;
	while (it != end)
	{
		std::cout << "pairs " << n << " : " << (*it)[0] << " | " << (*it)[1] << std::endl;
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

int	dqlen(std::deque<int>::const_iterator it, std::deque<int>::const_iterator end)
{
	size_t	len = 0;

	while (it != end)
	{
		len++;
		it++;
	}
	return (len);
}

void	dqswap(std::deque<int>::iterator left, std::deque<int>::iterator right)
{
	int	tmp = *left;

	*left = *right;
	*right = tmp;
}

// 14 89 1 3 99
// 14 89 | 1 3 99 [14 1], [89 3], 99
// 89 | 14 [89 14]
// 89
// 14 89
// 1 3 14 89 .. 99

int	dqlen(std::deque<int>::iterator it, std::deque<int>::iterator end)
{
	int	len = 0;

	while (it != end)
	{
		len++;
		it++;
	}
	return (len);
}

std::deque<int>::iterator	searchIndex(std::deque<int>::iterator it, std::deque<int>::iterator end, int target)
{
	int	mid = dqlen(it, end) / 2;
	while (*it < target)
	{
		if (*(it + mid) > target)
			std::advance(end, -(mid / 2));
		else
			std::advance(it, mid / 2);
	}
}

void	PmergeMe::mergeInsertionSort(std::deque<int> &origin, std::deque<int>::iterator it, std::deque<int>::iterator end)
{
	if (dqlen(it, end) < 2)
		return ;
	
	std::cout << "len : " << dqlen(it, end) << std::endl;
	
	std::deque<int *>	mainChain;
	std::deque<int>		halfDq;
	int	mid = dqlen(it, end) / 2;

	for (int i = 0; i < mid; i++)
	{
		if (*(it + i) < *(it + mid + i))
			dqswap(it + i, it + mid + i);
		int	*pair = new int[2];
		pair[0] = *(it + i);
		pair[1] = *(it + mid + i);
		mainChain.push_back(pair);
	}

	testPrint(it, end);
	testPrint(mainChain.begin(), mainChain.end());
	mergeInsertionSort(origin, it, it + mid);

	testPrint(it, end);
	testPrint(mainChain.begin(), mainChain.end());

}

void	PmergeMe::run(char **av)
{
	std::deque<int>		dq = inputToDq(av + 1);
	std::list<int *>	list;

	try
	{
		std::cout << "init ! -------------" << std::endl;
		testPrint(dq.begin(), dq.end());
		mergeInsertionSort(dq, dq.begin(), dq.end());
		testPrint(dq.begin(), dq.end());
		// binery search
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
