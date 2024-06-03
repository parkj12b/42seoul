/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:36:53 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:35:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_A_HPP__
# define __HUMAN_A_HPP__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);
	void	attack(void) const;
private:
	std::string	_name;
	Weapon		&_weapon;
};

#endif