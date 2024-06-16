/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:08:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 05:17:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <list>
#include <iostream>
#include <algorithm>
#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "=================================================\n";

  MutantStack<int> cmstack = mstack;
  cmstack.push(42);
  cmstack.push(43);
  cmstack.push(1);
  
  MutantStack<int>::iterator cit = cmstack.begin();

  while (cit != cmstack.end()) {
    std::cout << *cit << std::endl;
    ++cit;
  }

  std::cout << "Top: " << cmstack.top() << std::endl;
  std::cout << "Empty: " << cmstack.empty() << std::endl;
  std::cout << "Size: " << cmstack.size() << std::endl;

  return 0;
}