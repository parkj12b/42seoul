/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:33:24 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 19:05:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::~Span() {}

Span::Span(const Span &span) {
	*this = span;
}

Span &Span::operator=(const Span &span) {
	if (this == &span)
		return *this;
	_n = span._n;
	_v = span._v;
	return *this;
}

void	Span::addNumber(unsigned int n) {
	if (_v.size() >= _n)
		throw std::runtime_error("Span is full");
	_v.push_back(n);
}

unsigned int	Span::shortestSpan() {
	if (_v.size() <= 1)
		throw std::runtime_error("Span is empty or has only one element");
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	unsigned int min = UINT_MAX;
	for (unsigned int i = 1; i < v.size(); i++) {
		if (static_cast<unsigned int>(v[i] - v[i - 1]) < min)
			min = v[i] - v[i - 1];
	}
	return min;
}

unsigned int	Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::runtime_error("Span is empty or has only one element");
	std::vector<int> v = _v;
	std::sort(v.begin(), v.end());
	return v[v.size() - 1] - v[0];
}

std::vector<int>::iterator Span::begin() {
	return _v.begin();
}

std::vector<int>::iterator Span::end() {
	return _v.end();
}