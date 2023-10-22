/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:40 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/06 16:58:23 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	plus(int num1, int num2);
int	minus(int num1, int num2);
int	divide(int num1, int num2);
int	multiply(int num1, int num2);
int	mod(int num1, int num2);

int	op_num(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '/')
		return (2);
	if (op == '*')
		return (3);
	if (op == '%')
		return (4);
	return (5);
}

void	function_arr(int (*p[5])(int, int))
{
	p[0] = &plus;
	p[1] = &minus;
	p[2] = &divide;
	p[3] = &multiply;
	p[4] = &mod;
}
