/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:21:41 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 16:29:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

# include <string>

class Contact
{
	public:
		int	promptInfo(void);
		int	setFirstName(std::string input);
		int	setLastName(std::string input);
		int	setNickName(std::string input);
		int	setPhoneNumber(std::string input);
		int	setDarkestSecret(std::string input);
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string _darkestSecret;
};

#endif