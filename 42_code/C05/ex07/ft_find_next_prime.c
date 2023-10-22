/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 09:31:09 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/30 18:15:04 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_find_next_prime(int nb)
{
	unsigned int	i;
	int				found;

	if (nb == 3)
		return (3);
	if (nb <= 2)
		return (2);
	found = 0;
	while (!found)
	{
		found = 1;
		i = 2;
		while (i * i <= (unsigned int) nb)
		{
			if (nb % i++ == 0)
			{
				found = 0;
				break ;
			}
		}
		if (found)
			break ;
		nb++;
	}
	return (nb);
}
