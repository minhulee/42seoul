/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:44:27 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/13 22:50:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <cmath>
#include <iterator>

#define INVALID_INPUT -1

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

std::list<int>	PmergeMe::inputToLs(char **av)
{
	std::list<int>	ls;
	
	for (int i = 0; av[i] != NULL; i++)
	{
		int	target = invalidInput(av[i]);

		if (target == INVALID_INPUT)
			throw (InvalidInput());
		ls.push_back(target);
	}

	return (ls);
}

template<typename T>
void	itprint(typename T::const_iterator it, typename T::const_iterator end)
{
	while (it != end)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

template<typename T>
int	itlen(typename T::const_iterator it, typename T::const_iterator end)
{
	int	len = 0;
	
	while (it != end)
	{
		++len;
		++it;
	}
	return (len);
}



int	getJacobsthalNum(int max)
{
	int	pre = 0;
	
	for (int i = 1; i <= max; i++)
	{
		int	jacobsthalNum = (std::pow(2, i) - std::pow(-1, i)) / 3;
		if (max < jacobsthalNum)
			break ;
		else
			pre = jacobsthalNum;
	}

	return (pre);
}

std::deque<int> PmergeMe::getJacobsthalDq(int size)
{
	std::deque<int> jacobsthal;
	int	max = 0;
	int	pre = 0;

	for (int i = 0; i < size; i++)
	{
		if (max == 0)
		{
			max = getJacobsthalNum(size - i);
			pre = i;
		}
		jacobsthal.push_front(max + pre - 1);
		max--;
	}

	return jacobsthal;
}

std::deque<int>::iterator	searchIndex(std::deque<int>::iterator it, std::deque<int>::iterator end, int target)
{
	while (it < end)
	{
		std::deque<int>::iterator midIt = it + std::distance(it, end) / 2;

		if (*midIt == target)
			return midIt;
		else if (*midIt < target)
			it = midIt + 1;
		else
			end = midIt;
	}
	return it;
}

void	PmergeMe::mergeInsertionSort(std::deque<int>::iterator it, std::deque<int>::iterator end)
{
	int	len = itlen<std::deque<int> >(it, end);
	if (len < 2)
		return ;
	
	//std::cout << "len : " << len << std::endl;
	
	std::deque<int *>	mainChain;
	int	mid = len / 2;

	for (int i = 0; i < mid; i++)
	{
		if (*(it + i) < *(it + mid + i))
			std::swap(*(it + i), *(it + mid + i));
		int	*pair = new int[2];
		pair[0] = *(it + i);
		pair[1] = *(it + mid + i);
		mainChain.push_back(pair);
	}

	//testPrint(it, end);
	//testPrint(mainChain.begin(), mainChain.end());
	
	mergeInsertionSort(it, it + mid);

	std::deque<int>		halfDq(mainChain.size());
	std::copy(it, it + mainChain.size(), halfDq.begin());

	//std::cout << "before insertion ------- " << std::endl;
	//testPrint(halfDq.begin(), halfDq.end());
	//testPrint(mainChain.begin(), mainChain.end());

	// 야콥스탈 수열에 따른 a(k)에 대응되는 deque 생성
	std::deque<int>	jacobsthalDq = getJacobsthalDq(mid);
	//std::cout << "jacobsthalDq -------- " << std::endl;
	//testPrint(jacobsthalDq.begin(), jacobsthalDq.end());
	
	// 야콥스탈 수열을 통해 타켓 특정(0) -> 특정된 타켓(4)을 통해서 subcain 특정(5) -> 특정된 subcain을 가지고 해당 it - 1 까지 이진탐색 이후에 삽입
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		std::deque<int>::iterator	main = it;
		std::deque<int>::iterator	last = halfDq.begin() + i;
		std::advance(main, jacobsthalDq.back());
		std::advance(last, jacobsthalDq.back());
		jacobsthalDq.pop_back();

		int	sub = -1;

		for (size_t j = 0; j < mainChain.size(); j++)
		{
			if (*main == mainChain[j][0])
			{
				sub = mainChain[j][1];
				break ;
			}
		}

		//std::cout << "main : " << *main << " | sub : " << sub << std::endl;
		
		// 이진탐색
		//std::deque<int>::iterator	target = std::lower_bound(halfDq.begin(), last, sub);
		std::deque<int>::iterator	target = searchIndex(halfDq.begin(), last, sub);
		halfDq.insert(target, sub);
	}
	
	// 홀수개일 때, 남은 요소 전체 범위에 대해 탐색
	if (len % 2 == 1)
	{
		std::deque<int>::iterator	t = end - 1;
		std::deque<int>::iterator	target = std::lower_bound(halfDq.begin(), halfDq.end(), *t);
		halfDq.insert(target, *t);
	}
	
	std::copy(halfDq.begin(), halfDq.end(), it);
	
	//std::cout << "after insertion ------- " << std::endl;
	//testPrint(it, end);

	// 사용한 메인체인 제거
	for (size_t i = 0; i < mainChain.size(); i++)
		delete[] mainChain[i];
}

void	PmergeMe::run(char **av)
{
	try
	{
		std::deque<int>	dq = inputToDq(av + 1);
		std::list<int>	list = inputToLs(av + 1);
		clock_t	s, e;

		std::cout << "Before: ";
		itprint<std::deque<int> >(dq.begin(), dq.end());
		s = clock();
		mergeInsertionSort(dq.begin(), dq.end());
		e = clock();
		std::cout << "After: ";
		itprint<std::deque<int> >(dq.begin(), dq.end());
		std::cout << std::fixed << "Time to process a range of " << dq.size() << " elements with std::[deque] : " << double(e - s) / CLOCKS_PER_SEC << "us" << std::endl;
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
