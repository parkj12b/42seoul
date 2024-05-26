/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:50:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 18:16:20 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
	:_x(0), _y(0)
{
}

Point::Point(const float y, const float x)
	:_x(x), _y(y)
{
}

Point::Point(const Point &point)
	:_x(point._x), _y(point._y)
{
}

Point::~Point(void)
{
}

const Fixed	&Point::getX(void) const
{
	return (_x);
}

const Fixed	&Point::getY(void) const
{
	return (_y);
}