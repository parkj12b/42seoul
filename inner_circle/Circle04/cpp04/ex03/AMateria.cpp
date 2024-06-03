/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:50:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 14:20:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type)
	: _type(type)
{
}

std::string const	&AMateria::getType() const
{
	return _type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "What? I am printing something? " << target.getName() << std::endl;
}