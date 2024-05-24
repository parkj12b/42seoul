/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:27:11 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/22 20:13:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <string>

class Weapon {
public:
	Weapon(std::string);
	const std::string&	getType(void);
	void				setType(std::string type);
private:
	std::string	_type;
};

#endif