/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:33:36 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/04 20:54:04 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <cstdlib>
#include "Base.hpp"

int main()
{
	struct timeval cur_time;
	gettimeofday(&cur_time, NULL);
	srand(cur_time.tv_sec * 1000000 + cur_time.tv_usec);

	Base	*p = generate();
	Base	&r = *p;

	identify(p);
	identify(r);
}