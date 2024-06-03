/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:10:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:12:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap("default", 100, 100, 30)
{
	std::cout << "FragTrap constructor called. [" << _name << "]" << std::endl;
}

FragTrap::FragTrap(std::string name)
	: ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap constructor called. [" << _name << "]" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
	*this = fragTrap;	
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called. [" << _name << "]" << std::endl;
}

FragTrap	&FragTrap::operator= (const FragTrap &fragTrap)
{
	if (this != &fragTrap)
	{
		_name = fragTrap._name;
		_hitPoint = fragTrap._hitPoint;
		_energyPoint = fragTrap._energyPoint;
		_attackDamage = fragTrap._attackDamage;
	}
	return *this;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "highFiveGuys called -------------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "FragTrap " << _name << " is dead. Cannot perform action"
			<< std::endl;
		return ;
	}
	std::cout << "Let's do a high five!!!" << std::endl;
}

