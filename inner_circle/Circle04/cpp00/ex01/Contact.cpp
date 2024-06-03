/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:37:18 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 13:33:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "myDefines.hpp"

int	Contact::promptInfo(void)
{
	std::string	str;

	std::cout << "[Enter new contact info to add]" << std::endl;
	std::cout << "First Name: " << std::endl;
	std::getline(std::cin, str);
	if (!setFirstName(str))
		return (ERROR);
	std::cout << "Last Name: " << std::endl;
	std::getline(std::cin, str);
	if (!setLastName(str))
		return (ERROR);
	std::cout << "Nick Name: " << std::endl;
	std::getline(std::cin, str);
	if (!setNickName(str))
		return (ERROR);
	std::cout << "Phone Number: " << std::endl;
	std::getline(std::cin, str);
	if (!setPhoneNumber(str))
		return (ERROR);
	std::cout << "Darkest Secret: " << std::endl;
	std::getline(std::cin, str);
	if (!setDarkestSecret(str))
		return (ERROR);
	return (SUCCESS);
}

int	Contact::setFirstName(std::string input)
{
	if (input.length() == 0)
	{
		std::cerr << "Invalid: Empty field!" << std::endl;
		return (ERROR);
	}
	_firstName = input;
	return (SUCCESS);
}

int Contact::setLastName(std::string input)
{
	if (input.length() == 0)
	{
		std::cerr << "Invalid: Empty field!" << std::endl;
		return (ERROR);
	}
	_lastName = input;
	return (SUCCESS);
}

int Contact::setNickName(std::string input)
{
	if (input.length() == 0)
	{
		std::cerr << "Invalid: Empty field!" << std::endl;
		return (ERROR);
	}
	_nickName = input;
	return (SUCCESS);
}

int Contact::setPhoneNumber(std::string input)
{
	if (input.length() == 0)
	{
		std::cerr << "Invalid: Empty field!" << std::endl;
		return (ERROR);
	}
	_phoneNumber = input;
	return (SUCCESS);
}

int Contact::setDarkestSecret(std::string input)
{
	if (input.length() == 0)
	{
		std::cerr << "Invalid: Empty field!" << std::endl;
		return (ERROR);
	}
	_darkestSecret = input;
	return (SUCCESS);
}

std::string Contact::getFirstName(void)
{
	return (_firstName);
}

std::string Contact::getLastName(void)
{
	return (_lastName);
}

std::string Contact::getNickName(void)
{
	return (_nickName);
}

std::string Contact::getPhoneNumber(void)
{
	return (_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (_darkestSecret);
}
