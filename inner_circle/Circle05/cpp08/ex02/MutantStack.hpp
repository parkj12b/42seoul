/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:08:10 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 22:15:39 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
# define __MUTANTSTACK_HPP__

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack() {}
	~MutantStack() {}
	MutantStack(const MutantStack<T> &other) {
		*this = other;
	}
	MutantStack<T> &operator=(const MutantStack<T> &other) {
		if (this == &other)
			return *this;
		this->c = other.c;
		return *this;
	}
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
	const_iterator cbegin() { return this->c.cbegin(); }
	const_iterator cend() { return this->c.cend(); }
	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }
	const_reverse_iterator crbegin() { return this->c.crbegin(); }
	const_reverse_iterator crend() { return this->c.crend(); }
};

#endif