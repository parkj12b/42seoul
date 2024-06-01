/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:12:10 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:41:19 by minsepar         ###   ########.fr       */
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
	const Animal	*meta = new Animal();
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makesound();
	j->makesound();
	meta->makesound();

	delete meta;
	delete j;
	delete i;
	
	const WrongAnimal	*wMeta = new WrongAnimal();
	const WrongAnimal	*wCat = new WrongCat();

	std::cout << wCat->getType() << " " << std::endl;
	wMeta->makesound();
	wCat->makesound();
	
	delete wMeta;
	delete wCat;
}