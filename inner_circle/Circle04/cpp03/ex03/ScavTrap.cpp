/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:01:01 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 22:28:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	:ClapTrap("default", 100, 50, 20), _gateKeeperMode(false)
{
	std::cout << "ScavTrap constructor called. [" << _name << "]" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name, 100, 50, 20), _gateKeeperMode(false)
{
	std::cout << "ScavTrap constructor called. [" << name << "]" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called. [" << ClapTrap::_name << "]" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
	*this = scavTrap;
}

void	ScavTrap::attack(std::string target)
{
	std::cout << "[attack] called ---------------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "ScavTrap " << _name << " is dead. Cannot perform action" << std::endl;
		return ;
	}
	if (_energyPoint == 0)
	{
		printNotEnergyPoint();
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	reduceEnergyPoint(1);
}

ScavTrap	&ScavTrap::operator= (const ScavTrap &scavTrap)
{
	if (this != &scavTrap)
	{
		_name = scavTrap._name;
		_hitPoint = scavTrap._hitPoint;
		_energyPoint = scavTrap._energyPoint;
		_attackDamage = scavTrap._attackDamage;
	}
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "guardGate called ---------------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "ScavTrap [" << _name << "] is dead. Cannot take action"
			<< std::endl;
		return ;
	}
	if (_gateKeeperMode == true)
	{
		std::cout << "ScavTrap [" << _name << "] is already in gateKeeper mode"
			<< std::endl;
	}
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
	_gateKeeperMode = true;
}