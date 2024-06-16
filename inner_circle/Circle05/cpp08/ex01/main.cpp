/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:47:07 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 13:56:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "Span.hpp"

int main() {
  srand(time(NULL));

  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

  Span sp2 = Span(20000);
  sp2.addRange(sp.begin(), sp.end());

  std::vector<int>::iterator iter = sp2.begin();
  std::vector<int>::iterator end = sp2.end();

  while (iter != end) {
    std::cout << *iter << std::endl;
    iter++;
  }
  
  std::cout << "====================================" << std::endl;
  
  for (int i = 0; i < 10000; i++) {
    sp2.addNumber(rand());
  }
  
  std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
  std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;

}