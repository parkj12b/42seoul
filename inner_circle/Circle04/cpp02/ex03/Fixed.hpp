/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:37:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/24 23:13:13 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
 public:
  Fixed(void);
  Fixed(const int num);
  Fixed(const Fixed &fixed);
  Fixed(const float num);
  ~Fixed(void);
  Fixed &operator=(const Fixed &fixed);
  bool                operator>(const Fixed &fixed) const;
  bool                operator<(const Fixed &fixed) const;
  bool                operator>=(const Fixed &fixed) const;
  bool                operator<=(const Fixed &fixed) const;
  bool                operator==(const Fixed &fixed) const;
  bool                operator!=(const Fixed &fixed) const;
  Fixed               operator+(const Fixed &fixed) const;
  Fixed               operator-(const Fixed &fixed) const;
  Fixed               operator*(const Fixed &fixed) const;
  Fixed               operator/(const Fixed &fixed) const;
  Fixed               operator++(void);
  const Fixed         operator++(int);
  Fixed               operator--(void);
  const Fixed         operator--(int);
  int                 getRawBits(void) const;
  void                setRawBits(int const raw);
  float               toFloat(void) const;
  int                 toInt(void) const;
  static Fixed        &min(Fixed &a, Fixed &b);
  static const Fixed  &min(const Fixed &a, const Fixed &b);
  static Fixed        &max(Fixed &a, Fixed &b);
  static const Fixed  &max(const Fixed &a, const Fixed &b);
 private:
  int               _num;
  static const int  _fraction_bits;

};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);


#endif