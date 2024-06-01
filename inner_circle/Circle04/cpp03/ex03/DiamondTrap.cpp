/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:33:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 22:37:25 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

const FragTrap DiamondTrap::fragTrap = FragTrap();
const ScavTrap DiamondTrap::scavTrap = ScavTrap();


DiamondTrap::DiamondTrap(void)
	: ClapTrap("default", fragTrap.getHitPoint(), scavTrap.getEnergyPoint(),
		fragTrap.getAttackDamage()), _name("default")
{
	std::cout << "DiamondTrap constructor called. [" << _name << "]"
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name", fragTrap.getHitPoint(),
		scavTrap.getEnergyPoint(), fragTrap.getAttackDamage()), _name(name)
{
	std::cout << "DiamondTrap constructor called. [" << _name << "]"
		<< std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called. [" << ClapTrap::_name << "]"
		<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
	*this = diamondTrap;
}

DiamondTrap	&DiamondTrap::operator= (const DiamondTrap &diamondTrap)
{
	if (this != &diamondTrap)
	{
		ClapTrap::_name = diamondTrap.ClapTrap::_name;
		_name = diamondTrap._name;
		_hitPoint = diamondTrap._hitPoint;
		_energyPoint = diamondTrap._energyPoint;
		_attackDamage = diamondTrap._attackDamage;
	}
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "name: " << _name << " name claptrap: " << ClapTrap::_name
		<< std::endl;
}