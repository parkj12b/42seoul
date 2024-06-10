/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:49:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/04 20:19:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdint>
#include "Serializer.hpp"
#include "Data.hpp"

void	leaks()
{
	system("leaks exec.out");
}

int main()
{
	atexit(leaks);

	struct Data	*ptr = new Data();
	ptr->i = 0;
	ptr->f = 1;
	ptr->d = 2;
	ptr->str = "hello";
	uintptr_t	bytes = Serializer::serialize(ptr);
	
	std::cout << "bytes: " << bytes << std::endl;
	std::cout << "bytes in hex: " << std::hex << bytes << std::endl;

	struct Data	*data = Serializer::deserializer(bytes);

	std::cout << "data: " << data << std::endl;

	if (ptr == data)
	{
		std::cout << "two pointers are equal!" << std::endl;
	}
	else
	{
		std::cout << "not equal :(" << std::endl;
	}
	
	delete ptr;
}