/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:33:36 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/03 06:44:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm &shrubberyCreationForm)
	: AForm(shrubberyCreationForm.getName(), 145, 137), _target(shrubberyCreationForm._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

ShrubberyCreationForm	ShrubberyCreationForm::operator= (
	const ShrubberyCreationForm &shrubberyCreationForm)
{
	if (this != &shrubberyCreationForm)
	{
		_target = shrubberyCreationForm._target;
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	checkFormSigned();
	checkExecutePermission(executor);
	
	std::ofstream out((_target + "_shrubbery").c_str());
	if (!out.is_open())
	{
		throw std::runtime_error("failed to open file");
	}
	out << "            ,@@@@@@@,\n"
                 "    ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                 " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                 ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                 "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                 "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                 "`&%\\ ` /%&'    |.|        \\ '|8'\n"
                 "    |o|        | |         | |\n"
                 "    |.|        | |         | |\n"
                 " \\\\/ .\\_\\/\\/_/__/  ,\\_\\/\\/__\\\\/.  \\_\\/\\/__/_\n";
}
