/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:03:36 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/05 17:07:54 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe_io	**init_pipe_list(t_pipex_args *pipex_args, t_cmd *cmd)
{
	int			pipe_size;
	t_pipe_io	**pipe_list;

	pipe_size = pipex_args->argc - (cmd->num_command) - 2;
	pipe_list = safe_calloc(sizeof(t_pipe_io *), pipe_size + 1);
	while (pipe_size-- > 0)
		pipe_list[pipe_size] = safe_calloc(sizeof(t_pipe_io), 1);
	return (pipe_list);
}

void	init_cmd(t_cmd *cmd)
{
	cmd->cmd_dir = 0;
	cmd->cmd_argv = 0;
	cmd->num_command = 1;
	cmd->here_doc_flag = 0;
}

void	init_pipex_args(t_pipex_args *pipex_args,
			int argc, char **argv, char **envp)
{
	pipex_args->argc = argc;
	pipex_args->argv = argv;
	pipex_args->envp = envp;
}
