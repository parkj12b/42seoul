/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:44:28 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:39:29 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

void	HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType()
		<< std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
	:_name(name), _weapon(weapon)
{
}
