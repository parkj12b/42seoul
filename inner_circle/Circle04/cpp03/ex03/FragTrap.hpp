/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:13:31 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/27 23:12:16 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAG_TRAP_HPP__
# define __FRAG_TRAP_HPP__

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap(void);
	FragTrap			&operator= (const FragTrap &fragTrap);
	void				highFiveGuys(void);
};

#endif