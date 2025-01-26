/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:27:45 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/26 22:57:16 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template<typename T>
Array<T>::Array()
: arr(NULL), len(0)
{
	std::cout << "Array :: Constructor() called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
: arr(new T[n]()), len(n)
{
	std::cout << "Array :: Constructor(n) called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other)
: arr(new T[other.n]()), len(other.n)
{
	std::cout << "Array :: Copy Constructor() called" << std::endl;
	for (int i = 0; i < n; i++)
		arr[i] = other.arr[i];
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array :: Destructor() called" << std::endl;
}
