/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:30:06 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:42:40 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAT_HPP__
# define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &cat);
	Cat		&operator= (const Cat &cat);
	void	makesound(void) const;
};

#endif