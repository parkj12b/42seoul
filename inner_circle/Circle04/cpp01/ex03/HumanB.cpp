/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:47:25 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:44:27 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their ";
	std::cout << (_weapon != NULL ? _weapon->getType() : "hand :)")
		<< std::endl;
}

HumanB::HumanB(std::string name)
	:_name(name)
{
	_weapon = NULL;
}

HumanB::HumanB(std::string name, Weapon *weapon)
	:_name(name), _weapon(weapon)
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}