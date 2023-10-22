/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 08:55:31 by minsepar          #+#    #+#             */
/*   Updated: 2023/09/08 16:17:21 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *num1, char *num2)
{
	while (*num1 != 0 && *num2 != 0 && *num1 == *num2)
	{
		num1++;
		num2++;
	}
	return ((unsigned char) *num1 - (unsigned char) *num2);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;
	int		size;

	size = 0;
	i = 0;
	while (tab[size] != 0)
		size++;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}
