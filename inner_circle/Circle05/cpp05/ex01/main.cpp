/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:02:55 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/31 22:16:25 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat	a("jacob", 10);
	Form		form1("Dictator bill", 1, 1);
	Form		form2("Save the environment", 150, 10);
	
	
	try {
		Form		form3("Grade too high", 0, 10);
	} catch (const std::exception &e) {
		e.what();
	}
	try {
		Form		form4("Grade too low", 151, 151);
	} catch (const std::exception &e) {
		e.what();
	}
	
	Bureaucrat	b("dictator", 1);

	try {
		b.signForm(form1);
	} catch (const std::exception &e) {
		e.what();
	}
	a.signForm(form1);
	form2.beSigned(b);

	std::cout << std::endl << form1 << std::endl;
	std::cout << form2 << std::endl;
}