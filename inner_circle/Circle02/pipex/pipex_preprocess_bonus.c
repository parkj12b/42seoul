/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_preprocess_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:15:50 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/04 19:08:46 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**parse_path(t_pipex_args *pipex_args)
{
	int		i;
	char	**parsed_path;

	i = -1;
	parsed_path = 0;
	while (pipex_args->envp[++i])
	{
		if (ft_strncmp("PATH=", pipex_args->envp[i], 5) == 0)
		{
			parsed_path = ft_split(&(pipex_args->envp[i][5]), ':');
			break ;
		}
	}
	return (parsed_path);
}

void	set_read_fd(t_cmd *cmd, t_pipex_args *pipex_args, t_pipe_io **pipe_list)
{
	int		fd;
	int		pipe_index;

	if (cmd->num_command == 2
		|| (cmd->num_command == 3 && cmd->here_doc_flag == 1))
	{
		if (cmd->here_doc_flag == 1)
			fd = open(g_path, O_RDONLY);
		else
			fd = open(pipex_args->argv[cmd->num_command - 1], O_RDONLY);
		if (fd == -1)
			shell_error(pipex_args->argv[cmd->num_command - 1]);
		if (dup2(fd, 0) == -1)
			shell_error("pipex");
		close(fd);
	}
	else
	{
		pipe_index = cmd->num_command - 3 - cmd->here_doc_flag;
		if (dup2(pipe_list[pipe_index]->pipe_fd[0], 0) == -1)
			shell_error("pipex");
	}
}

static void	set_write_fd_helper(t_cmd *cmd,
			t_pipex_args *pipex_args)
{
	int		fd;
	char	*file_name_ptr;

	file_name_ptr = pipex_args->argv[cmd->num_command + 1];
	if (cmd->here_doc_flag == 1)
	{
		fd = open(file_name_ptr, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			shell_error(file_name_ptr);
	}
	else
	{
		fd = open(file_name_ptr, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			shell_error(file_name_ptr);
	}
	if (dup2(fd, 1) == -1)
		shell_error("pipex");
	close(fd);
}

void	set_write_fd(t_cmd *cmd,
			t_pipex_args *pipex_args, t_pipe_io **pipe_list)
{
	int		pipe_index;

	pipe_index = 0;
	if (cmd->num_command == pipex_args->argc - 2)
		set_write_fd_helper(cmd, pipex_args);
	else
	{
		pipe_index = cmd->num_command - 2 - cmd->here_doc_flag;
		if (dup2(pipe_list[pipe_index]->pipe_fd[1], 1) == -1)
			shell_error("pipex");
	}
	close(pipe_list[pipe_index]->pipe_fd[0]);
	close(pipe_list[pipe_index]->pipe_fd[1]);
}

char	*find_command_dir(char **parsed_path, t_cmd *cmd)
{
	int		i;
	int		malloc_size;
	char	*cmd_dir;

	i = -1;
	if (access(cmd->cmd_argv[0], X_OK | F_OK) == 0)
		return (ft_strdup(cmd->cmd_argv[0]));
	while (parsed_path[++i])
	{
		malloc_size = ft_strlen(parsed_path[i])
			+ ft_strlen(cmd->cmd_argv[0]) + 2;
		cmd_dir = safe_calloc(malloc_size, sizeof(char));
		ft_strlcat(cmd_dir, parsed_path[i], malloc_size);
		ft_strlcat(cmd_dir, "/", malloc_size);
		ft_strlcat(cmd_dir, cmd->cmd_argv[0], malloc_size);
		if (access(cmd_dir, X_OK | F_OK) == 0)
			return (cmd_dir);
		free(cmd_dir);
	}
	cmd_dir = 0;
	return (cmd_dir);
}
