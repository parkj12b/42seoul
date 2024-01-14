/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:29:20 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/04 16:12:01 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fatal_error(const char *message, t_cmd *cmd)
{
	write(STD_ERROR_FD, cmd->cmd_argv[0], ft_strlen(cmd->cmd_argv[0]));
	write(STD_ERROR_FD, ": ", 2);
	perror(message);
	exit(errno);
}

void	custom_error(const char *message, const char *target, int err_num)
{
	write(STD_ERROR_FD, "pipex: ", 7);
	write(STD_ERROR_FD, message, ft_strlen(message));
	write(STD_ERROR_FD, ": ", 2);
	write(STD_ERROR_FD, target, ft_strlen(target));
	write(STD_ERROR_FD, "\n", 1);
	exit(err_num);
}

void	shell_error(const char *target)
{
	char	*error_message;

	error_message = strerror(errno);
	write(STD_ERROR_FD, "pipex: ", 7);
	write(STD_ERROR_FD, error_message, ft_strlen(error_message));
	write(STD_ERROR_FD, ": ", 2);
	write(STD_ERROR_FD, target, ft_strlen(target));
	write(STD_ERROR_FD, "\n", 1);
	exit(errno);
}

void	eof_error(void)
{
	char	*message;

	message = "syntax_error: unexpected end of file\n";
	write(STD_ERROR_FD, "pipex: ", 7);
	write(STD_ERROR_FD, message, ft_strlen(message));
	exit(258);
}
