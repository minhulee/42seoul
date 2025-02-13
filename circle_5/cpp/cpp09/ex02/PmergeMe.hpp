/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:29:15 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/14 02:52:59 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

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
		static std::deque<int>	inputToDq(char **av);
		static std::list<int>	inputToLs(char **av);

		static std::deque<int> 	getJacobsthalDq(int size);
		static std::list<int> 	getJacobsthalLs(int size);

		static void				mergeInsertionSort(std::deque<int>::iterator, std::deque<int>::iterator);
		static void				mergeInsertionSort(std::list<int>::iterator, std::list<int>::iterator);

	/* exceptions */
	private:
		class	InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
