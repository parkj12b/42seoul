/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:04:21 by minsepar          #+#    #+#             */
/*   Updated: 2024/05/19 19:21:58 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TEST_H
# define TEST_H

class Calculator
{
	public:
		double	add(double a, double b);
		double	sub(double a, double b);
		double	mul(double a, double b);
		double	div(double a, double b);
		void	Init(void);
		void	showOpCount(void);
	private:
		int add_ops;
		int sub_ops;
		int mul_ops;
		int div_ops;
};

inline double	Calculator::add(double a, double b) { add_ops++; return(a + b);}
inline double	Calculator::sub(double a, double b) { sub_ops++; return(a - b);}
inline double	Calculator::mul(double a, double b) { mul_ops++; return(a * b);}
inline double	Calculator::div(double a, double b) { div_ops++; return(a / b);}

#endif