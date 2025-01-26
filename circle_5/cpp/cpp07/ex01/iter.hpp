/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 16:42:31 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/26 22:21:15 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
 #define ITER_HPP

#include <cstddef>

template<typename Tary, typename Tfunc>
void	iter(Tary arr, size_t len, Tfunc f)
{
	if (!arr)
		return ;
	for (size_t i = 0; i < len; i++)
		f(arr[i]);
}

template<typename T>
void	test(T &target)
{
	target += 1;
}

#endif