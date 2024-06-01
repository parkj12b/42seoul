/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:35:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 15:52:24 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	:AMateria("cure")
{	
}

Cure::~Cure()
{
}

Cure::Cure(const Cure &cure)
	:AMateria(cure.getType())
{
}
Cure	Cure::operator= (const Cure &rhs)
{
	if (this != &rhs)
	{
		_type = "cure";
	}
	return *this;
}

AMateria	*Cure::clone() const
{
	AMateria	*cure = new Cure();
	return	cure;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}