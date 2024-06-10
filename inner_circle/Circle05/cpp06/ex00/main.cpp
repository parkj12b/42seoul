/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:08:34 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/10 14:13:34 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "invalid number of arguments" << std::endl;
		return 0;
	}

	double f = 2147483648;
	std::cout << f << std::endl;

	// ScalarConverter temp;
	ScalarConverter::convert(argv[1]);
	return 0;
}