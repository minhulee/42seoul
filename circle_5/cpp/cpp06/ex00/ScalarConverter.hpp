/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:24:13 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/10 19:31:00 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter
{
	/* OCF */
	public:
		ScalarConverter();
		~ScalarConverter();
	
	private:
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
	
	/* Method */
	private:
		void		convertChar(std::string input)		const;
		void		convertInt(std::string input)		const;
		void		convertFloat(std::string input)		const;
		void		convertDouble(std::string input)	const;

	public:
		static void	convert(std::string	input);
	
	/* Member */
	/* Exception*/
};

#endif