/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:49:51 by minhulee          #+#    #+#             */
/*   Updated: 2025/01/21 18:14:03 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
 #define SERIALIZER_HPP

#include <cstdint>
#include "./Data.h"

class	Serializer
{
	/* OCF */
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &other);
		const Serializer	*operator=(const Serializer &other);

	/* Method*/
	public:
		static uintptr_t	serialize(Data *ptr); // uintptr_t -> 해당 시스템에 정의된 포인터 크기와 동일한 크기를 갖는다.
		static Data			*deserialize(uintptr_t raw);
	
};

#endif