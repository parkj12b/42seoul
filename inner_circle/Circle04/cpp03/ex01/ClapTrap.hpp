/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:27:34 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 18:59:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__

#include <string>

class ClapTrap {
protected:
	std::string	_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
	void			printNotEnergyPoint();
	void			reduceEnergyPoint(unsigned int amount);
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(std::string name, unsigned int hitPoint,
		unsigned int energyPoint, unsigned int attackDamage);
	~ClapTrap();
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap	&operator= (const ClapTrap &clapTrap);
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif