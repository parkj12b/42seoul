/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:12:07 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 17:41:07 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_HPP__
# define __ZOMBIE_HPP__

#include <string>

class Zombie {
public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void			announce(void);
	void			setName(std::string name);
private:
	std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif