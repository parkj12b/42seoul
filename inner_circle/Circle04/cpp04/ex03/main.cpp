/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:08:22 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 05:49:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

class Character;

void	leaks()
{
	system("leaks exec.out");
}

int main()
{
	atexit(leaks);
	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");
	
	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter	*bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "==========================================" << std::endl;

	tmp = src->createMateria("hehe");
	AMateria	*tmpMaterial = src->createMateria("ice");
	std::cout << "tmpMaterial addr: [" << tmpMaterial << "]" << std::endl;

	ICharacter	*person1 = new Character(*dynamic_cast<Character *>(me));
	ICharacter	*person2 = new Character(*dynamic_cast<Character *>(me));

	person1->equip(tmpMaterial);
	person1->use(0, *bob);
	
	person1->unequip(2);
	std::cout << "tmpMaterial addr: [" << tmpMaterial << "]" << std::endl;

	std::cout << tmpMaterial->getType() << std::endl;

	delete tmpMaterial;
	delete bob;
	delete me;
	delete src;
	delete person1;
	delete person2;

}