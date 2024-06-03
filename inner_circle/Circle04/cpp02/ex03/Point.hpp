/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:46:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 19:31:31 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

#include "Fixed.hpp"

class Point {
public:
	Point(void);
	~Point(void);
	Point(const Point &point);
	Point(const float y, const float x);
	const Fixed	&getX(void) const;
	const Fixed	&getY(void) const;
private:
	Point		&operator= (const Point &point);
	const Fixed	_x;
	const Fixed	_y;	
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif