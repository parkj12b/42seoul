/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:25:37 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/16 17:40:37 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

int main()
{
	char	*str;
	char	c;
    int		fd = open("test", O_RDONLY);

	if (fd == -1)
	{
		printf("failed open\n");
		return (0);
	}
	scanf("%c", &c);
	while (c == '\n')
	{
		str = get_next_line(fd);
		printf("%s", str);
		scanf("%c", &c);
	}
}