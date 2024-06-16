/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:02:53 by minsepar          #+#    #+#             */
/*   Updated: 2024/06/15 17:17:52 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EASYFIND_HPP__
# define __EASYFIND_HPP__

# include <algorithm>

template<typename T>
typename T::iterator easyfind(T &container, const int &toFind)
{
	typename T::iterator iter = find(container.begin(), container.end(), toFind);
	return iter;
}

#endif