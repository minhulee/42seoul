/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:57:32 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:01:37 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
 #define CURE_HPP

#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &other);
		~Cure();

		Cure			&operator=(const Cure &other);

		AMateria			*clone() const;
		void				use(ICharacter &target);
};

#endif