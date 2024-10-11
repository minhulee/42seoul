/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:19:43 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/11 17:22:57 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# include "./ClapTrap.hpp"

class	FragTrap : public	ClapTrap
{
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		virtual	~FragTrap();

		FragTrap	&operator=(const FragTrap &other);

		virtual void	attack(const std::string &target);
		void			highFivesGuys() const;

	private:
		FragTrap();
};