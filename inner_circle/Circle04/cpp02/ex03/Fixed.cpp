/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:24:15 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/25 01:22:53 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::_fraction_bits = 8;

Fixed::Fixed(void)
	:_num(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator= (const Fixed &fixed)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->_num = fixed._num;
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_num);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_num = raw;
}

Fixed::Fixed(const int num)
{
	// std::cout << "int constructor called" << std::endl;
	_num = num << _fraction_bits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "float constructor called" << std::endl;
	_num = roundf(num * (1 << _fraction_bits));
}

float	Fixed::toFloat(void) const
{
	return ((float)_num / (1 << _fraction_bits));
}

int		Fixed::toInt(void) const
{
	return (_num >> _fraction_bits);
}

std::ostream	&operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator> (const Fixed &fixed) const
{
	return (_num > fixed._num);
}

bool	Fixed::operator< (const Fixed &fixed) const
{
	return (_num < fixed._num);
}

bool	Fixed::operator>= (const Fixed &fixed) const
{
	return (_num >= fixed._num);
}

bool	Fixed::operator<= (const Fixed &fixed) const
{
	return (_num <= fixed._num);
}

bool	Fixed::operator== (const Fixed &fixed) const
{
	return (_num == fixed._num);
}

bool	Fixed::operator!= (const Fixed &fixed) const
{
	return (_num != fixed._num);
}

Fixed	Fixed::operator+ (const Fixed &fixed) const
{
	Fixed	ret(this->toFloat() + fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator- (const Fixed &fixed) const
{
	Fixed	ret(this->toFloat() - fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator* (const Fixed &fixed) const
{
	Fixed	ret(this->toFloat() * fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator/ (const Fixed &fixed) const
{
	Fixed	ret(this->toFloat() / fixed.toFloat());
	return (ret);
}

Fixed	Fixed::operator++(void)
{
	this->_num++;
	return *this;
}

const Fixed	Fixed::operator++(int)
{
	const Fixed fixed(*this);
	_num++;
	return (fixed);
}

Fixed	Fixed::operator--(void)
{
	this->_num--;
	return *this;
}

const Fixed	Fixed::operator--(int)
{
	const Fixed fixed(*this);
	_num--;
	return (fixed);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a._num > b._num ? b : a));
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	std::cout << "const" << std::endl;
	return ((a._num > b._num ? b : a));
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a._num < b._num ? b : a));
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	std::cout << "const" << std::endl;
	return ((a._num < b._num ? b : a));
}
