/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:38:06 by jacob             #+#    #+#             */
/*   Updated: 2024/06/06 16:12:02 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void	ft_print(int a)
{
	std::cout << a << std::endl;
}

void	add_one(int &a)
{
	a++;
}

template <typename U>
void	print(U a)
{
	std::cout << a << std::endl;
}

int main(void)
{
	int arr[5] = {1,2,3,4,5};

	iter(arr, 5, print<int>);
	std::cout << "============================================" << std::endl;
	iter(arr, 5, ft_print);
	std::cout << "============================================" << std::endl;
	iter(arr, 5, add_one);
	iter(arr, 5, ft_print);
	
}