/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacob <jacob@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:19:10 by jacob             #+#    #+#             */
/*   Updated: 2024/06/06 15:58:30 by jacob            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_HPP__
# define __ITER_HPP__

#include <cstddef>

template<typename T, typename U>
void	iter(T *arr, size_t len, U fn)
{
	if (arr == NULL || fn == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
	{
		fn(arr[i]);
	}
}

#endif