/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:15:27 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 14:49:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"
#include "ICharacter.hpp"

class ICharacater;

Ice::Ice()
	:AMateria("ice")
{	
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &ice)
	: AMateria(ice.getType())
{
}
Ice	Ice::operator= (const Ice &rhs)
{
	if (this != &rhs)
	{
		_type = "ice";
	}
	return *this;
}

AMateria	*Ice::clone() const
{
	AMateria	*ice = new Ice();
	return	ice;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bold at " << target.getName() << " *" << std::endl;
}
