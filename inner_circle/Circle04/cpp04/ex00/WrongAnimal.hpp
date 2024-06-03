/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:54:18 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:47:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_ANIMAL_HPP__
# define __WRONG_ANIMAL_HPP__

#include <string>

class WrongAnimal {
protected:
	std::string	_type;
public:
	WrongAnimal(void);
	WrongAnimal(std::string type);
	~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &wrongAnimal);
	WrongAnimal &operator= (const WrongAnimal &wrongAnimal);
	void			makesound(void) const;
	std::string		getType(void) const;
};


#endif