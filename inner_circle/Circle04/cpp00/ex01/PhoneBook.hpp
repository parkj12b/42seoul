/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:23:18 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 16:29:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include <string>
#include "Contact.hpp"

#define PHONE_BOOK_MAX 8
#define COLUMN_MAX_CHAR 10

class PhoneBook
{
	public:
		PhoneBook();
		int		add(void);
		int		search(void);
		int		displayContactList(void);
		void	displayElement(std::string str);
		int		displayContact(int idx);
	private:
		Contact	contacts[PHONE_BOOK_MAX];
		int		_index;
		bool	_full;
		void	displayContactListLine(int index);
};

# endif