/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:58:12 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/09 12:57:09 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BitcoinExchange_hpp
# define	BitcoinExchange_hpp

#include <map>
#include <string>
#include <exception>

class	BitcoinExchange
{
	/* user can acess only this func */
	public:
		static void		run(std::string);

	/* encapsulates the main funcs */
	private:
		static std::string	validDate(std::string);
		static float	validValue(std::string);
		static void		lineToMap(std::map<std::string, float> &, const char *, std::string);

		static void		loadData(std::map<std::string, float> &);
		// static void		loadInput(std::map<std::string, float> &, std::string);
		
		static void		inputExchangeData(std::map<std::string, float> &, std::string);

	/* exceptions */
	public:
		class	DataOpenFailed : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InputOpenFailed : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidFormat : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidDate : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	InvalidValue : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif