/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:29:15 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/12 17:36:54 by minhulee         ###   ########seoul.kr  */
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

		static void				makePair(std::deque<int *> &, const std::deque<int> &);
		static void				makePair(std::list<int *> &);

		static void				mergeInsertionSort(std::deque<int *>::iterator it, std::deque<int *>::iterator end);

	/* exceptions */
	private:
		class	InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif
