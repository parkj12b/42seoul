/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:34:15 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:13:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

Weapon::Weapon(std::string	type)
{
	setType(type);
}
