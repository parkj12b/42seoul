/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:38:26 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 19:46:32 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	diff(Fixed a, Fixed b)
{
	return ((a - b).toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point AB(diff(b.getX(), a.getX()), diff(b.getY(), a.getY()));
	Point BC(diff(c.getX(), b.getX()), diff(c.getY(), b.getY()));
	Point CA(diff(a.getX(), c.getX()), diff(a.getY(), c.getY()));
	Point AP(diff(point.getX(), a.getX()), diff(point.getY(), a.getY()));
	Point BP(diff(point.getX(), b.getX()), diff(point.getY(), b.getY()));
	Point CP(diff(point.getX(), c.getX()), diff(point.getY(), c.getY()));

	double cross1 = (AB.getX() * AP.getY()).toFloat()
		- (AB.getY() * AP.getX()).toFloat();
	double cross2 = (BC.getX() * BP.getY()).toFloat()
		- (BC.getY() * BP.getX()).toFloat();
	double cross3 = (CA.getX() * CP.getY()).toFloat()
		- (CA.getY() * CP.getX()).toFloat();

	return (cross1 > 0 && cross2 > 0 && cross3 > 0) ||
		(cross1 < 0 && cross2 < 0 && cross3 < 0);
}

