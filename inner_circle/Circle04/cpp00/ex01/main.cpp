/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:28:30 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 04:59:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include "PhoneBook.hpp"
#include "myDefines.hpp"

int	promptCommand(PhoneBook &phonebook)
{
	std::string input;
	
	std::cout << "Please enter a command [ADD, SEARCH, EXIT]: " << std::endl;
	std::getline(std::cin, input);
	if (input.compare("ADD") == 0)
		return (phonebook.add());
	else if (input.compare("SEARCH") == 0)
		return (phonebook.search());
	else if (input.compare("EXIT") == 0)
		exit(0);
	else
	{
		std::cout << "Invalid: Command does not exist" << std::endl;
		return (ERROR);
	}
}

int main(void)
{
	PhoneBook	phonebook;
	int			status;

	while (true)
	{
		status = promptCommand(phonebook);
		if (std::cin.eof() || status == ERROR)
		{
			std::cin.clear();
			clearerr(stdin);
		}
	}
}