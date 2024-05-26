/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:37:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 21:42:47 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const Fixed &fixed);
	Fixed(const float num);
	Fixed	&operator= (const Fixed &fixed);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int					_num;
	static const int	_fraction_bits;
};

std::ostream &operator<< (std::ostream &out, const Fixed &fixed);

#endif