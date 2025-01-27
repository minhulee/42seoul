/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 23:24:53 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/27 10:31:40 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
 #define ARRAY_TPP

#include <exception>
#include <iostream>
#include "Array.hpp"

template<typename T>
Array<T>::Array()
: len(0), arr(new T[len])
{
	std::cout << "Array :: Default Constructor() called" << std::endl;
}

template<typename T>
Array<T>::Array(const unsigned int n)
: len(n), arr(new T[len])
{
	std::cout << "Array :: Constructor(n) called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array &other)
: len(other.len), arr(new T[len])
{
	std::cout << "Array :: Copy Constructor() called" << std::endl;
	for (unsigned int i = 0; i < len; i++)
		arr[i] = other.arr[i];
}

template<typename T>
Array<T>::~Array()
{
	std::cout << "Array :: Destructor() called" << std::endl;
	delete [] arr;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	std::cout << "Array :: operator= called" << std::endl;
	if (this != &other)
	{
		if (arr)
		{
			std::cout << "delete arr !" << std::endl;
			delete [] arr;
		}
		len = other.len;
		arr = new T[len]();

		for (unsigned int i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](const unsigned int n)
{
	// std::cout << "Array :: operator[] called" << std::endl;
	if (len <= n)
		throw std::exception();
	return (arr[n]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	// std::cout << "Array :: Method :: size() called" << std::endl;
	return (len);
}

//template<typename T>
//const char	*Array<T>::OutOfRangeException::what() const throw()
//{
//	return ("Array :: Out of Range Exception !");
//}

#endif
