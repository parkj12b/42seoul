/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:28:44 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 17:35:37 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
private:
	std::string _name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif