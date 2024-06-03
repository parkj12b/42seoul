/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:43:57 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 20:44:03 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &intern)
{
	(void) intern;
}

Intern	Intern::operator=(const Intern &intern)
{
	(void) intern;
	return *this;
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	static std::string	forms[3] = {"president pardon", "robotomy request"
		,"shrubbery creation"};

	int numForm = -1;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			numForm = i;
			break ;
		}
	}
	AForm	*returnForm;
	switch (numForm)
	{
	case PRESIDENTIAL_PARDON_FORM:
		returnForm = new PresidentialPardonForm(target);
		break;
	case ROBOTOMY_REQUEST_FORM:
		returnForm = new RobotomyRequestForm(target);
		break;
	case SHRUBBERY_CREATION_FORM:
		returnForm = new ShrubberyCreationForm(target);
		break;
	default:
		throw NoSuchFormException();
	}
	std::cout << "Intern create " << forms[numForm] << std::endl;
	return (returnForm);
}

const char *Intern::NoSuchFormException::what() const throw()
{
	return "No such form exists.";
}