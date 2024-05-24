/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:13:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 18:18:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombieArr = new Zombie[N];
	std::stringstream	ss;

	for (int i = 0; i < N; i++)
	{
		ss.str("");
		ss << i + 1;
		zombieArr[i].setName(name + ss.str());
	}
	return (zombieArr);
}