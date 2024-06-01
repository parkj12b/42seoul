/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:10:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 16:51:28 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
	{
		ClapTrap a("a");
		
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
	}
	std::cout << "=============================================" << std::endl;
	{
		ClapTrap b("b");
		b.takeDamage(10);
		b.takeDamage(10);
		b.beRepaired(10);
		b.attack("a");
	}
}