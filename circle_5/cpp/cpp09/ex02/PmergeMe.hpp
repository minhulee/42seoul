/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:29:15 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/12 22:17:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <cstddef>
#include <exception>
#include <deque>
#include <list>

class	PmergeMe
{
	/* user can acess only this func */
	public:
		static void	run(char **av);

	/* encapsulates the main funcs */
	private:
		static std::deque<int>	getJacobsthalDeque(size_t count);
		static size_t			findInsertPoint(int value, std::deque<int*>& firstHalf);
		static std::deque<int>	inputToDq(char **av);
		static std::list<int>	inputToLs(char **av);

		static void				makePair(std::deque<int *> &, const std::deque<int> &);
		static void				makePair(std::list<int *> &);

		static void				mergeInsertionSort(std::deque<int> &, std::deque<int>::iterator, std::deque<int>::iterator);

	/* exceptions */
	private:
		class	InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
