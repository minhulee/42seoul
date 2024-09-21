/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:19:53 by minhulee          #+#    #+#             */
/*   Updated: 2024/09/21 14:48:06 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define	WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
	public:
		Weapon(const std::string &type);
		~Weapon();

		void				setType(const std::string &type);
		const std::string	&getType(void) const;

	private:
		std::string	type;
};

# endif
