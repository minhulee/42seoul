/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:58:12 by minhulee          #+#    #+#             */
/*   Updated: 2025/02/06 18:00:48 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	BitcoinExchange_hpp
# define	BitcoinExchange_hpp

#include <map>
#include <exception>

class	BitcoinExchange
{
	/* user can acess only this func */
	public:
		static void	run(std::string);

	/* encapsulates the main funcs */
	private:
		static void	validData(std::string line);
		static void	lineToMap(std::map<std::string, int> &map, const char *seperator, std::string line);
		static void	loadData(std::map<std::string, int> &map);
		static void	loadInput(std::ifstream &, std::string);
		static void	inputExchangeData(std::map<std::string, int> &, std::ifstream &);

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

		class	StrtodConvertFailed : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif