/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:30:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 22:36:51 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain	*_brain;
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &cat);
	Cat		&operator= (const Cat &cat);
	void	makesound(void) const;
	Brain	&getBrain(void) const;
};

#endif