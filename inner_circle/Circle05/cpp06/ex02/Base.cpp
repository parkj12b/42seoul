/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:32:41 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/10 14:31:49 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	int i = rand() % 3;
	switch (i) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return NULL;
}

void	identify(Base *p)
{
	std::cout << "Pointer Type: ";
	if (p == NULL)
		std::cout << "is a NULL pointer" << std::endl;
	else if (dynamic_cast<A *>(p))
	{
		std::cout << "type A" << std::endl;
	}
	else if (dynamic_cast<B *>(p))
	{
		std::cout << "type B" << std::endl;
	}
	else if (dynamic_cast<C *>(p))
	{
		std::cout << "type C" << std::endl;
	}
}

void	identify(Base &p)
{
	Base *tmp;

	std::cout << "Pointer Type: ";
	try {
		tmp = &dynamic_cast<A&>(p);
		std::cout << "type A" << std::endl;
	} catch (std::exception &e) {
		try {
			tmp = &dynamic_cast<B&>(p);
			std::cout << "type B" << std::endl;
		} catch (std::exception &e) {
			try {
				tmp = &dynamic_cast<C&>(p);
				std::cout << "type C" << std::endl;
			} catch (std::exception &e) {
				std::cout << "what?" << std::endl;
			}
		}
	}
	(void) tmp;
}