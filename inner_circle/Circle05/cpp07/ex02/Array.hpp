/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:49:35 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 13:49:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_HPP__
# define __ARRAY_HPP__

template <typename T>
class Array {
private:
	T 				*_arr;
	unsigned int	_size;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &array);
	Array	operator=(const Array &rhs);
	~Array();
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;
	unsigned int	size() const;

};

# include "Array.tpp"

#endif