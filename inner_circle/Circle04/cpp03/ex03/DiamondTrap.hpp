/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:52:17 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 22:36:15 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DIAMOND_TRAP_HPP__
# define __DIAMOND_TRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	static const FragTrap 	fragTrap;
	static const ScavTrap 	scavTrap;
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	DiamondTrap	&operator= (const DiamondTrap &diamondTrap);
	~DiamondTrap();
	void					whoAmI(void);
};

#endif
