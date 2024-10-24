/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:55:22 by minhulee          #+#    #+#             */
/*   Updated: 2024/10/24 19:09:50 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		const Brain	&operator=(const Brain &other);

		void				setIdea(const std::string &idea, int idx);
		const std::string	&getIdea(int idx);

	private:
		std::string	ideas[100];
};