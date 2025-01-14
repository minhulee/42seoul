/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 19:24:13 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/14 19:17:07 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
 #define SCALARCONVERTER_HPP

#include <string>

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
		int				getN(std::string &input);
		char			stoc(std::string &input);
		int				stoi(std::string &input);
		float			stof(std::string &input);
		double			stod(std::string &input);

		bool			convertJustChar(std::string &input);
		void			convertChar(std::string &input);
		void			convertInt(std::string &input);
		void			convertFloat(std::string &input);
		void			convertDouble(std::string &input);

	public:
		static void		convert(std::string	input);
	
	/* Member */
	/* Exception*/
	private:
		class	ConvertFailExc : public std::exception
		{
			public:
				const char * what() const throw();
		};
		
		class	OutOfRangeExc : public std::exception
		{
			public:
				const char * what() const throw();
		};
};

#endif