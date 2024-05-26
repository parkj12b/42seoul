/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:28:49 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 19:21:09 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int	main(void)
{
	Point v1(0, 0);
	Point v2(5, 0);
	Point v3(5, 5);
	
	Point p1(4, 1);
	Point p2(5, 6);
	Point p3(-1, 5);

	std::cout << "(4, 1) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, p1) << std::endl;
	std::cout << "(0, 0) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, v1) << std::endl;
	std::cout << "(5, 0) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, v2) << std::endl;
	std::cout << "(5, 5) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, v3) << std::endl;
	std::cout << "(5, 6) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, p2) << std::endl;
	std::cout << "(-1, 5) is inside triangle?: " << std::boolalpha
		<< bsp(v1, v2, v3, p3) << std::endl;
	
}