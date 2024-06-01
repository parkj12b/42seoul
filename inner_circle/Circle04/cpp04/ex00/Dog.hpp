/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:32:33 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:46:18 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOG_HPP__
# define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &dog);
	Dog		&operator= (const Dog &dog);
	void	makesound(void) const;
};

#endif