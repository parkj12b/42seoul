/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:52:38 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 18:32:50 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog(void) : Animal("Dog"), _brain(new Brain()) {
  std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::~Dog(void) {
  std::cout << "[Dog] destructor called" << std::endl;
  delete _brain;
}

Dog::Dog(const Dog &dog) { _brain = new Brain(*dog._brain); }

Dog &Dog::operator=(const Dog &dog) {
  if (this != &dog) {
    delete _brain;
    _type = dog._type;
    _brain = new Brain(*dog._brain);
  }
  return *this;
}

void Dog::makesound(void) const {
  std::cout << "Bark Bark I am a dog. I'm twerking on the runway" << std::endl;
}

Brain &Dog::getBrain(void) const { return *_brain; }
