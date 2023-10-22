/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:59:09 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/09 00:06:10 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_num(long num);
int		op_num(char c);
int		minus(int num1, int num2);
int		divide(int num1, int num2);
int		multiply(int num1, int num2);
int		mod(int num1, int num2);
void	function_arr(int (*p[5])(int, int));

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	division_modulo_by_zero(char operator, int num)
{
	if (num == 0)
	{
		if (operator == '/')
			write(1, "Stop : division by zero\n", 24);
		else if (operator == '%')
			write(1, "Stop : modulo by zero\n", 22);
		if (operator == '/' || operator == '%')
			return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	n;
	int	is_negative;

	n = 0;
	is_negative = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	n *= is_negative;
	return (n);
}

int	plus(int n1, int n2)
{
	return (n1 + n2);
}

int	main(int argc, char *argv[])
{
	int		num1;
	int		num2;
	int		(*p[5])(int, int);
	char	op;

	if (argc != 4)
		return (0);
	else
	{
		num1 = ft_atoi(argv[1]);
		num2 = ft_atoi(argv[3]);
		op = argv[2][0];
		if (ft_strlen(argv[2]) != 1 || !(op == '+' || op == '-'
				|| op == '/' || op == '*' || op == '%'))
		{
			write(1, "0\n", 2);
			return (0);
		}
		function_arr(p);
		if (division_modulo_by_zero(op, num2))
			return (0);
		print_num(p[op_num(op)](num1, num2));
		write(1, "\n", 1);
	}
}
