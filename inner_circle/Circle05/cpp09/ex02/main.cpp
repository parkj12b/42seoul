/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 20:01:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/18 22:18:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe	p;

	if (argc < 2)
	{
		std::cerr << "invalid number of arguments\n";
		return 1;
	}
	p.calculateJacobsthal(argc - 1);
	try {
		p.sortDeque(argv);
		p.sortVector(argv);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << p.getTimeDeque() << " us \n";
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << p.getTimeVector() << " us \n";

	

	return 0;
}