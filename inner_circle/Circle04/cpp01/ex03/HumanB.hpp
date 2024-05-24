/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:39:54 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:41:52 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMAN_B_HPP__
# define __HUMAN_B_HPP__

#include <string>
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon	*weapon);
	void	setWeapon(Weapon &weapon);
	void	attack(void);
private:
	std::string	_name;
	Weapon		*_weapon;
};

#endif