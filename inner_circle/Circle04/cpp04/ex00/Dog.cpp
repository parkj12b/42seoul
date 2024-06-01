/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:52:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 23:00:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog") {
  std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::~Dog(void) { std::cout << "[Dog] destructor called" << std::endl; }

Dog::Dog(const Dog &dog) { *this = dog; }

Dog &Dog::operator=(const Dog &dog) {
  if (this != &dog) {
    _type = dog._type;
  }
  return *this;
}

void Dog::makesound(void) const {
  std::cout << "Bark Bark I am a dog. I'm twerk on the runway" << std::endl;
}