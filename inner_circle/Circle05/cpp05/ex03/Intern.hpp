/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:44:18 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 17:07:40 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

#include <string>
#include "AForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern &intern);
	Intern	operator=(const Intern &intern);
	AForm	*makeForm(std::string formName, std::string target);
	class	NoSuchFormException : public std::exception
	{
		public:
			const char *what() const throw();
	};
	enum e_forms {
		PRESIDENTIAL_PARDON_FORM,
		ROBOTOMY_REQUEST_FORM,
		SHRUBBERY_CREATION_FORM
	};
};

#endif