/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:26:54 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 17:42:55 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "zombie : [" << name << "] created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "zombie : [" << _name << "] destroyed" << std::endl;
}

Zombie::Zombie(void) {}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}