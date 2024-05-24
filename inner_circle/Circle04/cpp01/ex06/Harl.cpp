/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:41:48 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 08:11:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string debugLevel[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning,
		&Harl::error};
	int numLevel = -1;
	
	for (int i = 0; i < 4; i++)
	{
		if (debugLevel[i] == level)
		{
			numLevel = i;
			break ;
		}
	}
	switch (numLevel)
	{
	case 0:
		(this->*f[0])();
		// fall through
	case 1:
		(this->*f[1])();
		// fall through
	case 2:
		(this->*f[2])();
		// fall through
	case 3:
		(this->*f[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for \
my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
		<< std::endl;

}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra \
bacon costs more money You didn't put enough bacon in my burger! If you \
did, I wouldn't be asking for more!"
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have \
some extra bacon for free. I've been coming for years whereas you started \
working here since last month."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want \
to speak to the manager now."
		<< std::endl;
}