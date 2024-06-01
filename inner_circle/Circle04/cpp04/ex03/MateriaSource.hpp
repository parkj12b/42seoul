/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:11:51 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 14:06:37 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIA_SOURCE_HPP__
# define __MATERIA_SOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_src[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource *materiaSource);
	MateriaSource operator= (const MateriaSource &rhs);
	void		learnMateria(AMateria *);
	AMateria	*createMateria(std::string const &type);
};

#endif