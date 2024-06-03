/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:38:53 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 14:16:08 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CHARACTER_HPP__
# define __CHARACTER_HPP__

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria		*_inventory[4];
	std::string		_name;
public:
	Character();
	Character(std::string name);
	~Character();
	Character(const Character &character);
	Character	operator= (const Character &rhs);
	std::string const	&getName() const;
	void		equip(AMateria *m);
	void		unequip(int idx);
	void		use(int idx, ICharacter &target);
};

#endif