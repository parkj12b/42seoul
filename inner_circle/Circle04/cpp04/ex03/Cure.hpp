/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:34:12 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 12:37:53 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	~Cure();
	Cure(const Cure &cure);
	Cure operator= (const Cure &rhs);
	AMateria	*clone() const;
	void		use(ICharacter &target);	
};

#endif
