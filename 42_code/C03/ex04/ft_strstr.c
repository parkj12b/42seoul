/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:19:06 by minsepar          #+#    #+#             */
/*   Updated: 2023/08/28 22:41:44 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		str_length;
	int		to_find_len;
	int		i;
	int		j;
	char	*current_str;

	i = 0;
	current_str = str;
	str_length = str_len(str);
	to_find_len = str_len(to_find);
	while (i < str_length - to_find_len + 1)
	{
		j = 0;
		while (current_str[j] != '\0' && to_find[j] != '\0'
			&& current_str[j] == to_find[j])
			j++;
		if (j == to_find_len)
			break ;
		current_str++;
		i++;
	}
	if (j == to_find_len)
		return (current_str);
	else
		return (0);
}
