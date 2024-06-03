/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:41:08 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 15:43:11 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		_src[i] = 0;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete _src[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource *materiaSource)
{
	for (int i = 0; i < 4; i++)
	{
		if (materiaSource->_src[i])
		{
			_src[i] = materiaSource->_src[i]->clone();
		}
		else
			_src[i] = NULL;
	}
}

MateriaSource	MateriaSource::operator= (const MateriaSource &rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete _src[i];
		if (rhs._src[i])
		{
			_src[i] = rhs._src[i]->clone();
		}
		else
			_src[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *src)
{
	for (int i = 0; i < 4; i++)
	{
		if (_src[i] == NULL)
		{
			_src[i] = src;
			return ;
		}
	}
	std::cout << "Already learned all 4 materia" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_src[i] == NULL)
			continue ;
		if (_src[i]->getType() == type)
		{
			return (_src[i]->clone());
		}
	}
	std::cout << "Template of materia " << type << " does not exist"
		<< std::endl;
	return 0;
}
