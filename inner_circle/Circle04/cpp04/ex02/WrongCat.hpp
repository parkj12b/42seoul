/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:10:46 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 19:47:01 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_CAT_HPP__
# define __WRONG_CAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &wrongCat);
	WrongCat	&operator= (const WrongCat &wrongCat);
	void		makesound(void) const;
};

#endif