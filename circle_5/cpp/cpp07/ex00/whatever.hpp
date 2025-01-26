/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:49:30 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/26 16:16:53 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WHATEVER_HPP
 #define	WHATEVER_HPP

class	tmp {};

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template<typename T>
T	min(T a, T b)
{
	return (a < b ? a : b);
}

template<typename T>
T	max(T a, T b)
{
	return (a > b ? a : b);
}

#endif
