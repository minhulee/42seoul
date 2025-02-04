/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:54:25 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/04 15:32:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
 #define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename Type, typename Stack = std::deque<Type> >
class	MutantStack : public std::stack<Type, Stack>
{
	/* custom typedef */
	public:
		typedef typename Stack::iterator		iterator;
		typedef typename Stack::const_iterator	const_iterator;

	/* custom iterator */
	public:
		iterator		begin();
		iterator		end();
		const_iterator	begin() const;
		const_iterator	end() const;
};

#include "./MutantStack.tpp"

#endif