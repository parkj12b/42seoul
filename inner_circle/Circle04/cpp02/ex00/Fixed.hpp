/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:37:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/23 20:58:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed	&operator= (const Fixed &fixed);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_num;
	static const int	_fraction_bits;
};

#endif