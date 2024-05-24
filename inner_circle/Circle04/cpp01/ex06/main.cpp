/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:46:36 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 17:27:32 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("ERROR1");
	harl.complain("E");
	harl.complain("info");
	harl.complain("");
	harl.complain("123");
	harl.complain("DEBUGG");
	harl.complain("INFOO");
	harl.complain("WARNIN");
	harl.complain("ERORR");
}