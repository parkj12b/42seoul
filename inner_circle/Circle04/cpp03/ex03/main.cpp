/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:10:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:59:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

void	leaks()
{
	system("leaks exec.out");
}

int main(void)
{
	atexit(leaks);
	{
		DiamondTrap a = DiamondTrap("a");
		
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
		a.highFiveGuys();
		a.whoAmI();
	}
	std::cout << "=============================================" << std::endl;
	{
		DiamondTrap b("b");
		b.takeDamage(100);
		b.attack("a");
		b.whoAmI();
	}
	{
		ClapTrap * a = new DiamondTrap("c");
		std::cout << "here" << std::endl;
		delete a;
	}
}