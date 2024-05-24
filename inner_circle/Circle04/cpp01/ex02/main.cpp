/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:56:22 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:25:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRIAN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory address of [string]: " << &str << std::endl;
	std::cout << "memory address of [stringPTR]: " <<  stringPTR << std::endl;
	std::cout << "memory address of [stringREF]: " <<  &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "value of [string]: " <<  str << std::endl;
	std::cout << "value of *pointer: " <<  *stringPTR
		<< std::endl;
	std::cout << "value of reference: " <<  stringREF << std::endl;
	return 0;
}