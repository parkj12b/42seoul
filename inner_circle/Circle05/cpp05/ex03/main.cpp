/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:13:09 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/03 15:27:11 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cstdlib>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	check()
{
	system("leaks exec.out");
}

int main()
{
	atexit(check);
	timeval	currentTime;
		
	gettimeofday(&currentTime, NULL);
	srand(currentTime.tv_sec * 1000000 + currentTime.tv_usec);
	Bureaucrat a("Dictator", 1);
	Bureaucrat b("Lowly Servant", 150);

	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		a.signForm(*rrf);
		a.executeForm(*rrf);
		delete rrf;
	}

	ShrubberyCreationForm	shrubbery("home");

	RobotomyRequestForm		robotomy("yeet");

	PresidentialPardonForm	pardon("pardon pls");
	
	Intern internA;

	try
	{
		AForm *rrf;

		rrf = internA.makeForm("blahblah", "target");
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	AForm	*shrubbery2 = internA.makeForm("shrubbery creation", "office");
	a.signForm(*shrubbery2);
	a.executeForm(*shrubbery2);
	AForm	*robotomy2 = internA.makeForm("robotomy request", "office");
	a.signForm(*robotomy2);
	a.executeForm(*robotomy2);
	AForm	*pardon2 = internA.makeForm("president pardon", "office");
	a.signForm(*pardon2);
	a.executeForm(*pardon2);

	delete shrubbery2;
	delete robotomy2;
	delete pardon2;
}