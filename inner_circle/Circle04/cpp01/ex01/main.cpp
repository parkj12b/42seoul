/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:30:46 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 07:40:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

void	leaks()
{
	system("leaks exec.out");
}

int	main(void)
{
	// atexit(leaks);
	Zombie	*zombieArr = zombieHorde(10, "bob");

	for (int i = 0; i < 10; i++)
	{
		zombieArr[i].announce();
	}
	delete []zombieArr;
	return 0;
}