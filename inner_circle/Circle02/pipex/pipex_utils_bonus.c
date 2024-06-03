/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 20:11:19 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/08 17:17:22 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "parser_bonus.h"

int	ft_isspace(int c)
{
	if (c >= 9 && c <= 12)
		return (1);
	if (c == 32)
		return (1);
	return (0);
}

int	is_str_limiter(const char *limiter, const char *str)
{
	int	limiter_len;
	int	str_len;

	limiter_len = ft_strlen(limiter);
	str_len = ft_strlen(str);
	if (limiter_len == str_len - 1
		&& ft_strncmp(limiter, str, limiter_len) == 0)
		return (1);
	return (0);
}

void	get_input_heredoc(t_pipex_args *pipex_args)
{
	char	*str;
	int		fd;

	fd = open(g_path, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		shell_error(g_path);
	write(STDOUT_FILENO, "pipe heredoc> ", 14);
	str = get_next_line(STDIN_FILENO);
	while (1)
	{
		if (!str)
		{
			str = get_next_line(STDIN_FILENO);
			continue ;
		}
		if (is_str_limiter(pipex_args->argv[2], str) == 1)
			break ;
		if (write(fd, str, ft_strlen(str)) == -1)
			shell_error(g_path);
		free(str);
		write(STDOUT_FILENO, "pipe heredoc> ", 14);
		str = get_next_line(STDIN_FILENO);
	}
	if (str)
		free(str);
}

void	free_2d_pointer(void **pointer)
{
	int	i;

	i = -1;
	if (!pointer)
		return ;
	while (pointer[++i])
	{
		free(pointer[i]);
	}
	free(pointer);
}
