/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:37:15 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 18:36:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "myDefines.hpp"

PhoneBook::PhoneBook(void)
{
	_index = 0;
	_full = false;
}

int	PhoneBook::add(void)
{
	Contact	*newContact = &contacts[_index];
	
	if (!newContact->promptInfo())
		return (ERROR);
	_index++;
	if (_index >= PHONE_BOOK_MAX)
	{
		_full = true;
		_index %= PHONE_BOOK_MAX;
	}
	return (SUCCESS);
}

void	PhoneBook::displayElement(std::string str)
{
	int	dotFlag = false;
	int numLeftSpace = COLUMN_MAX_CHAR - str.length();

	if (numLeftSpace < 0)
	{
		numLeftSpace = 0;
		dotFlag = true;
	}
	// for (int i = 0; i < numLeftSpace; i++)
	// 	std::cout << ' ';
	if (dotFlag)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << '|';
}

void	PhoneBook::displayContactListLine(int index)
{
	Contact	*contact = &contacts[index];
	std::string	str;
	
	std::cout << '|';
	for (int i = 0; i < 4; i++)
	{
		switch(i){
			case 0:
				str = index + '0';
				break;
			case 1:
				str = contact->getFirstName();
				break;
			case 2:
				str = contact->getLastName();
				break;
			case 3:
				str = contact->getNickName();
				break;
		}
		displayElement(str);
	}
	std::cout << std::endl;
}

int PhoneBook::displayContactList(void)
{
	int numDisplay = _index;
	
	if (_index == 0 && _full == false)
	{
		std::cout << "Invalid: No contact to display" << std::endl;
		return (ERROR);
	}
	if (_full == true)
		numDisplay = PHONE_BOOK_MAX;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < numDisplay; i++)
		displayContactListLine(i);
	std::cout << "---------------------------------------------" << std::endl;
	return (SUCCESS);
}

int	PhoneBook::displayContact(int idx)
{
	Contact	&contact = contacts[idx];

	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickName() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	return (SUCCESS);
}

int PhoneBook::search(void)
{
	std::string	input;
	int			idx;

	if (!displayContactList())
		return (ERROR);
	std::cout << "Enter the index of entry" << std::endl;
	std::getline(std::cin, input);
	if (input.length() != 1)
	{
		std::cerr << "Invalid index" << std::endl;
		return (ERROR);
	}
	if (input[0] < '0' && input[0] > '9')
		return (ERROR);
	idx = input[0] - '0';
	if (idx < 0 || idx >= PHONE_BOOK_MAX || (idx >= _index && _full == false))
	{
		std::cout << "Invalid index" << std::endl;
		return (ERROR);
	}
	displayContact(idx);
	return (SUCCESS);
}
