/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:09:25 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/06 08:20:32 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
 #define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		~Ice();

		AMateria	*clone() const;
		void		use(ICharacter &target);

	private:
		Ice				&operator=(const Ice &other);
};

#endif