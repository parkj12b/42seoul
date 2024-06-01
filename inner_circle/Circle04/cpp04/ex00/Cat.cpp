/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:45:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 23:00:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include <iostream>

Cat::Cat(void) : Animal("Cat") {
  std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::~Cat(void) { std::cout << "[Cat] destructor called" << std::endl; }

Cat::Cat(const Cat &cat) { *this = cat; }

Cat &Cat::operator=(const Cat &cat) {
  if (this != &cat) {
    _type = cat._type;
  }
  return *this;
}

void Cat::makesound(void) const {
  std::cout << "Meow Meow. I am a cat. I walk on frozen Han Gang." << std::endl;
}