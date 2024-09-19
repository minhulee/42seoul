/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:46:48 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/19 09:07:38 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBock.hpp"

void	check(void)
{
	system("leaks phonebook");
}

int	main(void)
{
	PhoneBook	phoneBook;	
	
	atexit(check);
	phoneBook.RUN();
}