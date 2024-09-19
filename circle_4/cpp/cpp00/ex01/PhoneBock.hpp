/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBock.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:07:07 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/19 09:06:12 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>

# include "./Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook				();
		~PhoneBook				();
		
		void	RUN				(void);

	private:
		void	ADD				(void);
		void	SEARCH			(void) const;
		void	EXIT			(void) const;
		void	LOGO			(void) const;
		bool	isValidInput	(std::string &input) const;
		bool	isValidOrder	(std::string &input) const;
		void	PRINT			(std::string input, std::string end) const;
		void	PRINT			(int cursor) const;

		Contact	contacts[8];
		int		cursor;
		int		saved;
};