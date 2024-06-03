/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 22:02:55 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/03 15:14:34 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat	person("jacob", 2);
		
		person.incrementGrade();
		std::cout << person << std::endl;
		
		// person.incrementGrade();
		// std::cout << person << std::endl;
		

		
		Bureaucrat	person1("jacob", 149);
		
		person1.decrementGrade();
		std::cout << person1 << std::endl;
		
		// person.decrementGrade();
		// std::cout << person << std::endl;



		// Bureaucrat	person2("bob", 0);
		Bureaucrat	person3("johnson", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}