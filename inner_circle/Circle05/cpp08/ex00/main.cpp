/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:04:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 17:23:39 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	std::vector<int>::iterator iter1 = easyfind(v, 1);
	
	if (iter1 != v.end())
		std::cout << "Found: " << *iter1 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	iter1 = easyfind(v, 0);
	if (iter1 != v.end())
		std::cout << "Found: " << *iter1 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::deque<int> d(v.begin(), v.end());

	std::deque<int>::iterator iter2 = easyfind(d, 2);
	
	if (iter2 != d.end())
		std::cout << "Found: " << *iter2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	iter2 = easyfind(d, 0);
	if (iter2 != d.end())
		std::cout << "Found: " << *iter2 << std::endl;
	else
		std::cout << "Not found" << std::endl;
	
	std::list<int> l(v.begin(), v.end());
	std::list<int>::iterator iter3 = easyfind(l, 3);
	
	if (iter3 != l.end())
		std::cout << "Found: " << *iter3 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	iter3 = easyfind(l, 0);
	if (iter3 != l.end())
		std::cout << "Found: " << *iter3 << std::endl;
	else
		std::cout << "Not found" << std::endl;

}