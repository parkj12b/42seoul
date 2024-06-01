/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:05:45 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 20:05:02 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCAV_TRAP_HPP__
# define __SCAV_TRAP_HPP__

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	bool	_gateKeeperMode;
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap(void);
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap		&operator= (const ScavTrap &scavTrap);
	void	attack(std::string target);
	void	guardGate(void);
};

#endif