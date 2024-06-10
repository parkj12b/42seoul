/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:38:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/10 14:30:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
	Serializer();
	Serializer(const Serializer &serializer);
	Serializer	operator= (const Serializer &rhs);
	~Serializer();
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserializer(uintptr_t raw);
};

#endif
