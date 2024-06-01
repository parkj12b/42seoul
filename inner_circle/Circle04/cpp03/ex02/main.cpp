/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:10:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:20:00 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main(void)
{
	{
		FragTrap a = FragTrap("a");
		
		a.highFiveGuys();
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
	}
	std::cout << "=============================================" << std::endl;
	{
		FragTrap b("b");
		b.takeDamage(100);
		b.attack("a");
		b.highFiveGuys();
	}
}