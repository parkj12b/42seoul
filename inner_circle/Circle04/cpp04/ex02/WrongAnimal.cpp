/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:12:05 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 23:00:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal(void) {
  std::cout << "[WrongAnimal] default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "[WrongAnimal] default constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "[WrongAnimal] destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) {
  *this = wrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
  if (this != &wrongAnimal) {
    _type = wrongAnimal._type;
  }
  return *this;
}

void WrongAnimal::makesound(void) const {
  std::cout << "This is a WrongAnimal class. :\\ What sound should I make?"
            << std::endl;
}

std::string WrongAnimal::getType(void) const { return _type; }