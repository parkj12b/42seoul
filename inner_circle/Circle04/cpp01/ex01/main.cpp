/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:30:46 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:25:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

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