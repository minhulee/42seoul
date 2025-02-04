/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:07:38 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/04 15:39:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_TPP
 #define	MUTANTSTACK_TPP

#include "./MutantStack.hpp"

template <typename Type, typename Stack>
typename MutantStack<Type, Stack>::iterator MutantStack<Type, Stack>::begin()
{
	return this->c.begin();
}

template <typename Type, typename Stack>
typename MutantStack<Type, Stack>::iterator MutantStack<Type, Stack>::end()
{
	return this->c.end();
}

template <typename Type, typename Stack>
typename MutantStack<Type, Stack>::const_iterator MutantStack<Type, Stack>::begin() const
{
	return this->c.begin();
}

template <typename Type, typename Stack>
typename MutantStack<Type, Stack>::const_iterator MutantStack<Type, Stack>::end() const
{
	return this->c.end();
}

#endif