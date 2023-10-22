/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:59:26 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/08 19:50:38 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	if (length == 0)
		return (1);
	while (i < length - 1 && f(tab[i], tab[i + 1]) >= 0)
		i++;
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) <= 0)
		i++;
	if (i == length - 1)
		return (1);
	return (0);
}
