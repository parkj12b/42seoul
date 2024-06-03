/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:23:42 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/03 06:44:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sys/time.h>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{	
}

RobotomyRequestForm::RobotomyRequestForm
	(const RobotomyRequestForm &robotomyRequestForm)
	: AForm("RobotomyRequestForm", 72, 45), _target(robotomyRequestForm._target)
{
}

RobotomyRequestForm	RobotomyRequestForm::operator= (
	const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkFormSigned();
	checkExecutePermission(executor);
	
	std::cout << "I can hear a drilling noise..." << std::endl;
	int num = rand();
	if (num % 2 == 0)
	{
		std::cout << "The " << _target << " has been robotomized." << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed." << std::endl;
	}
}