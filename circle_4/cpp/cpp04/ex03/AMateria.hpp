/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:59:31 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 15:11:51 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AMATERIA_HPP
 #define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(const std::string &type);
		virtual ~AMateria();

		const std::string	&getType() const; //Returns the materia type
		
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);

	protected:
		std::string	type;
	
	private:
		AMateria();
};

#endif
