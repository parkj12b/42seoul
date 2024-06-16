/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:25:09 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 19:10:56 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
# define __SPAN_HPP__

#include <iostream>
#include <vector>

class Span {
private:
	unsigned int _n;
	std::vector<int> _v;
	Span();
public:
	~Span();
	Span(const Span &span);
	Span(unsigned int n);
	Span &operator=(const Span &span);
	void			addNumber(unsigned int n);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	std::vector<int>::iterator begin();
	std::vector<int>::iterator end();
	template <typename T>
	void	addRange(T begin, T end) 
	{
		std::copy(begin, end, std::back_inserter(_v));
	}
};

#endif