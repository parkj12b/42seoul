/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:34:48 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 22:59:52 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain] constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
}

Brain	&Brain::operator=(const Brain &brain)
{
	if (this != &brain)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = brain._ideas[i];
	}
	return *this;
}

std::string	Brain::getIdeas(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Index out of range" << std::endl;
		return NULL;
	}
	return _ideas[i];
}

void	Brain::setIdeas(int i, std::string idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "Index out of range" << std::endl;
		return ;
	}
	_ideas[i] = idea;
}