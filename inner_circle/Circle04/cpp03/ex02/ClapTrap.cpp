/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:22:40 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:30:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called. [" << _name << "]" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called. [" << name << "]" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hitPoint,
		unsigned int energyPoint, unsigned int attackDamage)
	:	_name(name), _hitPoint(hitPoint), _energyPoint(energyPoint),
		_attackDamage(attackDamage)
{
	std::cout << "ClapTrap constructor called. [" << name << "]" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called. [" << _name << "]" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap)
{
	*this = clapTrap;
}

ClapTrap	&ClapTrap::operator= (const ClapTrap &clapTrap)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &clapTrap)
	{
		_name = clapTrap._name;
		_hitPoint = clapTrap._hitPoint;
		_energyPoint = clapTrap._energyPoint;
		_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "[attack] called ---------------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Cannot perform action" << std::endl;
		return ;
	}
	if (_energyPoint == 0)
	{
		printNotEnergyPoint();
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	reduceEnergyPoint(1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[takeDamage] called ------------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " has taken " << amount
		<< " of damage" << std::endl;
	if (amount >= _hitPoint)
	{
		std::cout << "ClapTrap " << _name << " has died" << std::endl;
		_hitPoint = 0;
	}
	else
		_hitPoint -= amount;
		
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[beRepaired] called -----------------------" << std::endl;
	if (_hitPoint == 0)
	{
		std::cout << "ClapTrap " << _name << " is dead. Cannot take action"
			<< std::endl;
		return ;
	}
	if (_energyPoint == 0)
	{
		printNotEnergyPoint();
		return ;
	}
	_hitPoint += amount;
	std::cout << "ClapTrap " << _name << " has repaired " << amount
		<< " of hit points. It is now " << _hitPoint << std::endl;
	reduceEnergyPoint(1);
}

void	ClapTrap::printNotEnergyPoint()
{
	std::cout  << "[" << _name << "] " << "not enough energy point" << std::endl;
}

void	ClapTrap::reduceEnergyPoint(unsigned int amount)
{
	if (amount > _energyPoint)
		return ;
	_energyPoint -= amount;
	std::cout << "Energy point is now " << _energyPoint << std::endl;
}