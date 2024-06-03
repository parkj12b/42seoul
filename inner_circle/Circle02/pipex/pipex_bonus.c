/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:27:07 by minsepar          #+#    #+#             */
/*   Updated: 2024/02/17 15:16:35 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "parser_bonus.h"

void	process_child(t_cmd *cmd,
			t_pipex_args *pipex_args, t_pipe_io **pipe_list)
{
	set_read_fd(cmd, pipex_args, pipe_list);
	set_write_fd(cmd, pipex_args, pipe_list);
	set_command_path(cmd, pipex_args);
	if (!cmd->cmd_dir)
		custom_error("command not found", cmd->cmd_argv[0], 127);
	if (execve(cmd->cmd_dir, cmd->cmd_argv, pipex_args->envp) == -1)
		shell_error(cmd->cmd_argv[0]);
	free_2d_pointer((void **)cmd->cmd_argv);
	free(cmd->cmd_dir);
}

void	set_command_path(t_cmd *cmd, t_pipex_args *pipex_args)
{
	char	**parsed_path;

	parsed_path = parse_path(pipex_args);
	cmd->cmd_argv = string_parser(pipex_args->argv[cmd->num_command]);
	cmd->cmd_dir = find_command_dir(parsed_path, cmd);
	free_2d_pointer((void **)parsed_path);
}

int	wait_processes(pid_t last_pid, pid_t first_pid, t_cmd *cmd)
{
	int	wstatus;
	int	status_code;

	waitpid(last_pid, &wstatus, 0);
	if (cmd->here_doc_flag)
	{
		if (waitpid(first_pid, NULL, 0) == -1)
			unlink(g_path);
	}
	if (WIFEXITED(wstatus))
	{
		status_code = WEXITSTATUS(wstatus);
	}
	while (1)
	{
		if (wait(NULL) == -1 && errno == ECHILD)
			break ;
	}
	return (status_code);
}

int	process_command(t_pipex_args *pipex_args, t_cmd *cmd)
{
	int			error_num;
	pid_t		pid;
	pid_t		first_pid;
	t_pipe_io	**pipe_list;

	pipe_list = init_pipe_list(pipex_args, cmd);
	while (++(cmd->num_command) <= pipex_args->argc - 2)
	{
		pipe(pipe_list[cmd->num_command - 2 - cmd->here_doc_flag]->pipe_fd);
		pid = fork();
		if (pid == 0)
			process_child(cmd, pipex_args, pipe_list);
		else if (cmd->num_command == 3 && cmd->here_doc_flag)
			first_pid = pid;
		if (cmd->num_command > 2 + cmd->here_doc_flag)
			close(pipe_list[cmd->num_command
				- 3 - cmd->here_doc_flag]->pipe_fd[0]);
		close(pipe_list[cmd->num_command - 2 - cmd->here_doc_flag]->pipe_fd[1]);
	}
	close(pipe_list[pipex_args->argc - 4 - cmd->here_doc_flag]->pipe_fd[0]);
	error_num = wait_processes(pid, first_pid, cmd);
	free_2d_pointer((void **)pipe_list);
	return (error_num);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_args	pipex_args;
	t_cmd			cmd;
	int				exit_status;

	if (argc < 5)
		return (1);
	init_pipex_args(&pipex_args, argc, argv, envp);
	init_cmd(&cmd, &pipex_args);
	if (cmd.here_doc_flag == 1 && argc < 6)
		return (1);
	if (cmd.here_doc_flag == 1)
		get_input_heredoc(&pipex_args);
	exit_status = process_command(&pipex_args, &cmd);
	return (exit_status);
}
