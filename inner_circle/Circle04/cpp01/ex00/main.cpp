/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:51:58 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 07:40:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

void	leaks()
{
	system("leaks exec.out");
}

int main(void)
{
	atexit(leaks);
	Zombie *zombie2;
	{
		Zombie zombie1("a");
		
		zombie2 = new Zombie("b");
		zombie1.announce();
		zombie2->announce();
		std::cout << std::endl << "randomChump called" << std::endl;
		randomChump("c");
		std::cout << "randomChump call end" << std::endl << std::endl;
		delete(zombie2);
	}
	// delete (zombie2);
	return 0;
}