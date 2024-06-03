/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:48:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 15:35:57 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm &presidentialPardonForm)
	: AForm("PresidentialPardonForm", 25, 5)
	, _target(presidentialPardonForm._target)
{
}

PresidentialPardonForm	PresidentialPardonForm::operator= (
	const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	checkFormSigned();
	checkExecutePermission(executor);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}