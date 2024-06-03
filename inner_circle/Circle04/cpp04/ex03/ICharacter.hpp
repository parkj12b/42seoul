/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:33:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 14:19:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICHARACTER_HPP__
# define __ICHARACTER_HPP__

#include <string>
class	AMateria;

class ICharacter
{
public:
	virtual ~ICharacter() {};
	virtual std::string const &getName() const = 0;
	virtual void	equip(AMateria *m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;
};

#endif