/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:42:11 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 17:00:46 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "./ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &other);
		virtual	~ScavTrap();

		ScavTrap	&operator=(const ScavTrap &other);

		virtual void	attack(const std::string &target);
		void			guardGate() const;

	private:
		ScavTrap();
};