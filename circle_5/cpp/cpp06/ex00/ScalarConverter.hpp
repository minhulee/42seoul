/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:24:13 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/13 22:23:22 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class	ScalarConverter
{
	/* OCF */
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter	&operator=(const ScalarConverter &other);
	
	/* Method */
	private:
		std::string		isInf(std::string &input);
		std::string		isNan(std::string &input);
		bool			isNumber(std::string &input);

		int				strToInt(std::string &input);
		float			strToFloat(std::string &input);
		double			strToDouble(std::string &input);

		void			convertChar(std::string &input);
		void			convertInt(std::string &input);
		void			convertFloat(std::string &input);
		void			convertDouble(std::string &input);

	public:
		static void		convert(std::string	input);
		// ㅇㅒ느ㄴ 호출될 때 객체가 없으 수도 있다.
		// 모든 함수를 static으로 하던가
		// convert 내부에서 scalar를 잠깐 만들던가
	
	/* Member */
	/* Exception*/
};

#endif