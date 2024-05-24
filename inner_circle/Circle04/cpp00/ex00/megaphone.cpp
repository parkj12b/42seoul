/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:32:17 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 16:11:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

void	str_to_upper(char *str)
{
	while (*str)
	{
		*str = std::toupper(*str);
		str++;
	}
}

int main(int argc, char **argv)
{
	int		i;

	std::cout << std::uppercase;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 0;
		while (++i < argc)
		{
			str_to_upper(argv[i]);
			std::cout << argv[i];
		}
	}
	std::cout << std::uppercase << std::endl;	
}