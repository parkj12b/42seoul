/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:57:18 by marvin            #+#    #+#             */
/*   Updated: 2024/06/06 13:57:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array()
	: _arr(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _arr(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &array)
	: _arr(new T[array._size]), _size(array._size)
{
	for (unsigned int i = 0; i < array._size; i++)
	{
		_arr[i] = array[i];
	}
}

template <typename T>
Array<T>	Array<T>::operator= (const Array &rhs)
{
	if (this != &rhs)
	{
		_arr = new T[rhs._size];
		for (unsigned int i = 0; i < rhs._size; i++)
		{
			_arr[i] = rhs._arr[i];
		}
		_size = rhs._size;
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (_arr == NULL)
		return ;
	delete [] _arr;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size || _arr == NULL)
		throw std::out_of_range("array index out of range");
	return _arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size || _arr == NULL)
		throw std::out_of_range("array index out of range");
	return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}