/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 09:44:03 by minhulee          #+#    #+#             */
/*   Updated: 2024/08/25 10:10:06 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{
	public:
		Harl();
		~Harl();

		void		complain(std::string level);

	private:
		void		(Harl::*func[4])(void);
		std::string	filter[4];
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
};

#endif