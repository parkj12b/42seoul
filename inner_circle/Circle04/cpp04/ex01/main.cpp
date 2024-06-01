/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:12:10 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 18:33:46 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"

void	leaks(void)
{
	system("leaks exec.out");
}

int main(void)
{
	atexit(leaks);
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();
	
	delete j;
	delete i;
	
	std::cout << "============================" << std::endl;

	Animal *arr[10];

	for (int i = 0; i < 5; i++)
	{
		arr[i] = new Dog();
	}
	for (int j = 5; j < 10; j++)
	{
		arr[j] = new Cat();
	}

	// Dog a = Dog();
	// Dog b = Dog();
	// for (int i = 0; i < 100; i++)
	// 	b.getBrain().setIdeas(i, "twerk");
	// a = b;
	// for (int i = 0; i < 100; i++)
	// 	b.getBrain().setIdeas(i, ".");

	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		std::cout << a.getBrain().getIdeas(i * 10 + j) + " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		std::cout << b.getBrain().getIdeas(i * 10 + j) + " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	
	// Cat c = Cat();
	// Cat d = Cat();
	// for (int i = 0; i < 100; i++)
	// 	d.getBrain().setIdeas(i, "nyan");
	// c = d;
	// for (int i = 0; i < 100; i++)
	// 	d.getBrain().setIdeas(i, ".");

	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		std::cout << c.getBrain().getIdeas(i * 10 + j) + " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// for (int i = 0; i < 10; i++)
	// {
	// 	for (int j = 0; j < 10; j++)
	// 	{
	// 		std::cout << d.getBrain().getIdeas(i * 10 + j) + " ";
	// 	}
	// 	std::cout << std::endl;
	// }

	std::cout << "===========================" << std::endl;

	Dog	dogOutside;
	Cat	catOutside;

	{
		Dog	dogInside;
		Cat catInside;
		dogInside.getBrain().setIdeas(0, "twerk");
		catInside.getBrain().setIdeas(0, "nyan");
		dogOutside = dogInside;
		catOutside = catInside;
	}

	std::cout << "dogOutside idea: " << dogOutside.getBrain().getIdeas(0) << std::endl;
	std::cout << "catOutside idea: " << catOutside.getBrain().getIdeas(0) << std::endl;
	std::cout << "===========================" << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		delete arr[i];
	}

	Dog tmp;
	{
		Dog doggg = tmp;
	}
	
}