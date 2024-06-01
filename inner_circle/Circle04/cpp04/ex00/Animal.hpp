/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:28:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:38:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <string>

class Animal {
protected:
	std::string	_type;
public:
	Animal(void);
	Animal(std::string type);
	virtual ~Animal(void);
	Animal(const Animal &animal);
	Animal &operator= (const Animal &animal);
	virtual void	makesound(void) const;
	std::string		getType(void) const;
};

#endif