/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:45:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 18:32:19 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal("Cat"), _brain(new Brain()) {
  std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::~Cat(void) {
  std::cout << "[Cat] destructor called" << std::endl;
  delete _brain;
}

Cat::Cat(const Cat &cat) {
  _brain = new Brain(*cat._brain);
}

Cat &Cat::operator=(const Cat &cat) {
  if (this != &cat) {
    delete _brain;
    _type = cat._type;
    _brain = new Brain(*cat._brain);
  }
  return *this;
}

void Cat::makesound(void) const {
  std::cout << "Meow Meow. I am a cat. I walk on frozen Han Gang." << std::endl;
}

Brain &Cat::getBrain(void) const { return *_brain; }
