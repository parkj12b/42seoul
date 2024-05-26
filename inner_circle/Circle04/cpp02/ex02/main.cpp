/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:28:49 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 19:22:48 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	Fixed const	c(Fixed(5.05f) / Fixed(2));
	Fixed const	d(Fixed(5.05f) + Fixed(2));
	Fixed const	e(Fixed(5.05f) - Fixed(2));
	Fixed const	two(2);
	Fixed const	three(3);
	Fixed		noConstZero;
	Fixed		noConstTwo(2);
	Fixed		noConstThree(3);
	Fixed		negativeVal(-2.2f);
	
	std::cout << "[Pre/Post Increment Operator]" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max(a,b) << std::endl;

	std::cout << std::endl << "[Pre/Post Decrement Operator]" << std::endl;
	
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	
	std::cout << std::endl << "[Arithmetic Operators]" << std::endl;
	std::cout << "5.05 * 2 = " << b << std::endl;
	std::cout << "5.05 / 2 = " << c << std::endl;
	std::cout << "5.05 + 2 = " << d << std::endl;
	std::cout << "5.05 - 2 = " << e << std::endl;

	std::cout << std::endl << "[Comparison Operators]" << std::endl;
	std::cout << std::boolalpha;
	std::cout << "5.05 > 2  is " << (Fixed(5.05f) > Fixed(2)) << std::endl;
	std::cout << "2.001 > 2 is (expect false) " << (Fixed(2.001f) > Fixed(2))
		<< std::endl;
	std::cout << "5.05 < 2  is " << (Fixed(5.05f) < Fixed(2)) << std::endl;
	std::cout << "2.001 < 2 is (expect false) " << (Fixed(2.001f) < Fixed(2))
		<< std::endl;
	
	std::cout << std::endl << "[Min / Max]" << std::endl;
	std::cout << "Max(5.05, 2): " << Fixed::max(Fixed(5.05f), Fixed(2))
		<< std::endl;
	std::cout << "Max(2, 3): " << Fixed::max(two, three) << std::endl;
	
	std::cout << "Min(3, 2): " << Fixed::min(noConstTwo, noConstThree)
		<< std::endl;

	std::cout << std::endl << "[division by zero]" << std::endl;
	std::cout << Fixed(0) / Fixed(0) << std::endl;

	std::cout << 0.0 / 0.0 << std::endl;
	float	f = 0.0 / 0.0;
	std::cout << std::hex << *((unsigned int *)&f) << std::endl;
	std::cout << (int)roundf(f) << std::endl;

	std::cout << std::endl << "[Min / Max]" << std::endl;
	std::cout << "5 * -2.2 = " << Fixed(5) * negativeVal << std::endl;
	return 0;
}