/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:12:45 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/06 08:28:24 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CPP
 #define CHARACTER_CPP

#include "./ICharacter.hpp"
#include "./AMateria.hpp"

class	Character : public ICharacter
{
	public:
		Character(const std::string &name);
		Character(const Character &other);
		~Character();

		Character	&operator=(const Character &other);

		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
		AMateria			*exportMateria(int idx);

	private:
		Character();
		std::string	name;
		AMateria	*slot[4];
};

#endif