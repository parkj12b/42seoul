/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:35:25 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 05:44:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "[Animal] default constructor called." << std::endl;
}

Animal::Animal(const std::string &type)
	:_type(type)
{
	std::cout << "[Animal] default constructor called." << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "[Animal] destructor called." << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
}

Animal &Animal::operator= (const Animal &animal)
{
	if (this != &animal)
	{
		_type = animal._type;
	}
	return *this;
}

void	Animal::makesound(void) const
{
	std::cout << "This is a Animal class. :\\ What sound should I make?" << std::endl;
}

std::string	Animal::getType(void) const
{
	return _type;
}