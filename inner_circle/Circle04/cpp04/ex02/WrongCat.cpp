/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:12:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 23:00:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
  std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "[WrongCat] destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) { *this = wrongCat; }

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
  if (this != &wrongCat) {
    _type = wrongCat._type;
  }
  return *this;
}

void WrongCat::makesound(void) const {
  std::cout << "Meow Meow. I am a wrongCat. I walk on frozen Han Gang."
            << std::endl;
}