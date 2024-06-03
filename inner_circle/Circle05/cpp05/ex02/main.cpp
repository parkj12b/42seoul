/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:13:09 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/03 06:42:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cstdlib>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
	timeval	currentTime;
		
	gettimeofday(&currentTime, NULL);
	srand(currentTime.tv_sec * 1000000 + currentTime.tv_usec);
	Bureaucrat a("Dictator", 1);
	Bureaucrat b("Lowly Servant", 150);
	ShrubberyCreationForm	shrubbery("home");

	RobotomyRequestForm		robotomy("yeet");

	PresidentialPardonForm	pardon("pardon pls");
	
	a.executeForm(shrubbery);
	a.executeForm(robotomy);	
	a.executeForm(pardon);

	a.signForm(shrubbery);
	a.signForm(robotomy);
	a.signForm(pardon);

	a.executeForm(shrubbery);
	a.executeForm(robotomy);	
	a.executeForm(pardon);
	
	b.executeForm(shrubbery);
}