/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:52:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/01 05:36:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::~Dog(void) { std::cout << "[Dog] destructor called" << std::endl; }

Dog::Dog(const Dog &dog)
  : Animal(dog._type)
{
}

Dog &Dog::operator=(const Dog &dog) {
  if (this != &dog) {
    _type = dog._type;
  }
  return *this;
}

void Dog::makesound(void) const {
  std::cout << "Bark Bark I am a dog. I'm twerk on the runway" << std::endl;
}