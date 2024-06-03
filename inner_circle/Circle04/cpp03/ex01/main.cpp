/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:10:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:19:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap a = ScavTrap("a");
		
		a.attack("b");
		a.beRepaired(1);
		a.attack("b");
		a.beRepaired(1);
		a.attack("b");
		a.beRepaired(1);
		a.attack("b");
		a.beRepaired(1);
		a.attack("b");
		a.beRepaired(1);
		a.attack("b");
		a.guardGate();
	}
	std::cout << "=============================================" << std::endl;
	{
		ScavTrap b("b");
		b.takeDamage(100);
		b.guardGate();
		b.attack("a");
	}
}