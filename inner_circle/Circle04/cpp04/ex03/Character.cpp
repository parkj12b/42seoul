/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:43:39 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 15:56:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
	}
}

Character::Character(const Character &character)
{
	for (int i = 0; i < 4; i++)
	{
		if (character._inventory[i])
			_inventory[i] = character._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character	Character::operator= (const Character &character)
{
	if (this == &character)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete _inventory[i];
		if (character._inventory[i])
		{
			_inventory[i] = character._inventory[i]->clone();
		}
		else
			_inventory[i] = NULL;
	}
	return *this;
}

std::string const	&Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	AMateria	*materia = _inventory[idx];
	
	if (materia == NULL)
		return ;
	materia->use(target);
}