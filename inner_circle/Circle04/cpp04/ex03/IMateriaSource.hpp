/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:36:11 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/30 13:40:01 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IMATERIA_SOURCE_HPP__
# define __IMATERIA_SOURCE_HPP__

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;	
};

#endif