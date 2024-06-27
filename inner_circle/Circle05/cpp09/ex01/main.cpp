/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:09:43 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 15:19:45 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string expression = argv[1];
	try {
		rpn.calculateExpression(expression);
		std::cout << rpn.getResult() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}