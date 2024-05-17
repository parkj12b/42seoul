/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsepar <minsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:47:32 by minsepar          #+#    #+#             */
/*   Updated: 2024/01/05 17:07:06 by minsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define STD_ERROR_FD 2

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./libft/get_next_line_bonus.h"

static const char	*g_path = "/tmp/pipex_heredoc_tmp";

typedef struct s_pipe_io
{
	int	pipe_fd[2];
}	t_pipe_io;

typedef struct s_cmd
{
	int		num_command;
	int		here_doc_flag;
	char	*cmd_dir;
	char	**cmd_argv;
}	t_cmd;

typedef struct s_pipex_args
{
	char	**argv;
	char	**envp;
	int		argc;
}	t_pipex_args;

/* safe_wrapped.c */
void		*safe_malloc(size_t size);
void		*safe_calloc(size_t size, size_t num);

/* pipex.c */
void		process_child(t_cmd *cmd,
				t_pipex_args *pipex_args, t_pipe_io **pipe_list);
void		set_command_path(t_cmd *cmd, t_pipex_args *pipex_args);
int			wait_processes(pid_t last_pid, pid_t first_pid, t_cmd *cmd);
int			process_command(t_pipex_args *pipex_args, t_cmd *cmd);

/* pipex_init.c */
t_pipe_io	**init_pipe_list(t_pipex_args *pipex_args, t_cmd *cmd);
void		init_cmd(t_cmd *cmd);
void		init_pipex_args(t_pipex_args *pipex_args,
				int argc, char **argv, char **envp);

/* pipex_preprocess.c */
char		**parse_path(t_pipex_args *pipex_args);
void		set_read_fd(t_cmd *cmd,
				t_pipex_args *pipex_args, t_pipe_io **pipe_list);
void		set_write_fd(t_cmd *cmd,
				t_pipex_args *pipex_args, t_pipe_io **pipe_list);
char		*find_command_dir(char **parsed_path, t_cmd *cmd);

/* error.c */
void		fatal_error(const char *message, t_cmd *cmd);
void		shell_error(const char *target);
void		custom_error(const char *message, const char *target, int err_num);
void		eof_error(void);

/* pipex_utils.c */
int			ft_isspace(int c);
int			is_str_limiter(const char *limiter, const char *str);
void		get_input_heredoc(t_pipex_args *pipex_args);
void		free_2d_pointer(void **pointer);

#endif