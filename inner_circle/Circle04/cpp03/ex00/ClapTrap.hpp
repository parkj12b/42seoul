/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:27:34 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 17:03:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__

#include <string>

class ClapTrap {
private:
	std::string	_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;
	void			printNotEnergyPoint();
	void			reduceEnergyPoint(unsigned int amount);
	ClapTrap(void);
public:
	ClapTrap(std::string _name);
	~ClapTrap(void);
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap	&operator= (const ClapTrap &clapTrap);
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif