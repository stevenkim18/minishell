/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/20 16:30:16 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <stdbool.h>

# define STDOUT 1
# define STDIN 0

# define ECHO_STR "echo"
# define CD_STR "cd"
# define PWD_STR "pwd"
# define EXPORT_STR "export"
# define ENV_STR "env"
# define UNSET_STR "unset"
# define EXIT_STR "exit"

# define SHELL_STR_L "MINISHELL >> "
# define SHELL_STR_S "minishell: "
# define EXIT_STR "exit"
# define NEWLINE_STR "\n"

# define SPACE_STR " "
# define SEMICOLON_STR ";"
# define PIPE_STR "|"

# define IGNORE_INT "\b\b  \b\b"

# define NO_ERROR 0
# define ENOINT_P 1
# define ENOCMD 127
# define ENOINT 130
# define ENOTKN 258

# define ENOCMD_STR "command not found: "
# define ENOTKN_STR "syntax error near unexpected token "
# define ENOTKN_S "`;\'"
# define ENOTKN_P "`|\'"

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);

# define READ 0
# define WRITE 1

void	ft_end_process(const int error, int index, const pid_t pid);
void	ft_start_process(pid_t *pid);
void	ft_exec_process(int (*ft_exec_command)(const char *, int *),
								const char *command, int *index);

void	ft_put_error(const int error_num);
int		ft_handle_error(const int error_num, void *content);

void	ft_open_pipe(int fd[2]);
void	ft_close_pipe(int fd[2]);
void	ft_send_int(const int signal, int fd[2]);
int		ft_get_int(int fd[2]);
void	ft_send_str(char *str, int fd[2]);
char	*ft_get_str(int fd[2]);

int		*ft_get_data_pipe(void);
int		*ft_get_error_pipe(void);
int		*ft_get_index_pipe(void);
int		ft_get_index(void);
void	ft_set_index(int index);

void	ft_handle_parent_signal(int signal);
void	ft_handle_child_signal(int signal);
void	ft_register_parent_signal(void);
void	ft_register_child_signal(void);

int		ft_verify_pipe(const char *command, const int index);
int		ft_verify_semicolon(const char *command, const int index);
int		ft_verify_command(const char *command);

void	ft_handle_command(void);
void	ft_exec_commnad(const char *command);

int		ft_handle_pwd(const char *command, int *index);

#endif
