/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:08:02 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/16 13:59:00 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <list>
#include <iostream>
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
  mstack.swap(cmstack);

  MutantStack<int>::iterator mstackIter = mstack.begin();
  MutantStack<int>::iterator cmstackIter = cmstack.begin();

  std::cout << std::endl << "=============================" << std::endl;

  while (mstackIter != mstack.end()) {
    std::cout << *mstackIter << std::endl;
    ++mstackIter;
  }
  std::cout << std::endl << "=============================" << std::endl;

  while (cmstackIter != cmstack.end()) {
    std::cout << *cmstackIter << std::endl;
    ++cmstackIter;
  }

  return 0;
}