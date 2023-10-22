/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:38:28 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/30 18:30:08 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	n;

	n = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (n);
	else
	{
		while (nb > 1)
		{
			n *= nb;
			nb -= 1;
		}
	}
	return (n);
}
