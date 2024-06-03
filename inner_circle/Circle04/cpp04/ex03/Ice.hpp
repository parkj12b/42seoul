/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:08:17 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 12:33:41 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	Ice(const Ice &ice);
	Ice operator= (const Ice &rhs);
	AMateria	*clone() const;
	void		use(ICharacter &target);
};



#endif