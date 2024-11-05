/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 22:04:37 by minhulee          #+#    #+#             */
/*   Updated: 2024/11/05 17:02:00 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
 #define MATERIASOURCE_HPP

#include "./IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		~MateriaSource();

		MateriaSource	&operator=(const MateriaSource &other);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string &type);
	
	private:
		AMateria	*source[4];
};

#endif