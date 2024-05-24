/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/19 19:22:34 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "test.h"

using namespace std;

void Calculator::Init(void)
{
	add_ops = 0;
	sub_ops = 0;
	div_ops = 0;
	mul_ops = 0;
}

void Calculator::showOpCount(void)
{
	cout << "덧셈: " << add_ops << " 뺄셈: " << sub_ops << " 곱셈: " << mul_ops << " 나눗셈: " << div_ops << endl;
}

int main(void)
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.sub(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.div(4.9, 1.2)<<endl;
	cal.showOpCount();
}