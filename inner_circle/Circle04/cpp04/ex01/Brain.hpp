/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:55:30 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/28 22:23:27 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP__
# define __BRAIN_HPP__

#include <string>

class Brain {
private:
	std::string	_ideas[100];
public:
	Brain(void);
	~Brain(void);
	Brain(const Brain &brain);
	Brain	&operator=(const Brain &brain);
	std::string	getIdeas(int i) const;
	void		setIdeas(int i, std::string idea);
};

#endif