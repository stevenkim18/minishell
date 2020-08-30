/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:03:04 by dakim             #+#    #+#             */
/*   Updated: 2020/08/31 02:50:08 by stevenkim        ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>

# define STDOUT 1
# define STDIN 0

# define ECHO_STR "echo"
# define ECHO_D "\"echo\""
# define ECHO_S "\'echo\'"
# define CD_STR "cd"
# define CD_D "\"cd\""
# define CD_S "\'cd\'"
# define PWD_STR "pwd"
# define PWD_D "\"pwd\""
# define PWD_S "\'pwd\'"
# define EXPORT_STR "export"
# define EXPORT_D "\"export\""
# define EXPORT_S "\'export\'"
# define ENV_STR "env"
# define ENV_D "\"env\""
# define ENV_S "\'env\'"
# define UNSET_STR "unset"
# define UNSET_D "\"unset\""
# define UNSET_S "\'unset\'"
# define EXIT_STR "exit"
# define EXIT_D "\"exit\""
# define EXIT_S "\'exit\'"

# define SHELL_STR_L "MINISHELL >> "
# define SHELL_STR_S "minishell: "
# define EXIT_STR "exit"
# define NEWLINE_STR "\n"

# define SPACE_STR " "
# define SEMICOLON_STR ";"
# define PIPE_STR "|"

# define IGNORE_INT "\b\b  \b\b"

# define EMPTY_STR ""

# define NO_ERROR 0
# define ENOINT_P 1
# define ENOCMD 127
# define ENODIR -127
# define ENOINT 130
# define ENOQUIT 1
# define ENOTKN 258
# define ENOTKN_P 258
# define ENOTKN_S -258
# define ENONUMARG 255
# define ENOARGS 1

# define ENOCMD_STR ": command not found"
# define ENODIR_STR ": No such file or directory"
# define ENOARGS_STR ": too many arguments"
# define ENONUMARG_STR ": numeric argument required"
# define ENOTKN_S_STR "syntax error near unexpected token `;\'"
# define ENOTKN_P_STR "syntax error near unexpected token `|\'"

int			get_next_line(int fd, char **line);
char		*ft_trim_str(const char *str);

# define READ 0
# define WRITE 1

pid_t		ft_get_pid(void);
void		ft_end_process(const int error, int index, const pid_t pid);
void		ft_start_process(pid_t *pid);
void		ft_exec_process(int (*ft_exec_command)(const char *, int *),
								const char *command, int *index);
bool		ft_get_fork_status(void);
void		ft_set_fork_status(bool status);

void		ft_put_error(const int error_num);
int			ft_handle_error(const int error_num, void *content);

void		ft_open_pipe(int fd[2]);
void		ft_close_pipe(int fd[2]);
void		ft_send_int(const int signal, int fd[2]);
int			ft_get_int(int fd[2]);
void		ft_send_str(char *str, int fd[2]);
char		*ft_get_str(int fd[2]);

int			*ft_get_data_pipe(void);
int			*ft_get_error_pipe(void);
int			*ft_get_index_pipe(void);
void		ft_flush_pipe(const char *str);

int			ft_get_index(void);
void		ft_set_index(int index);
int			ft_get_last_index(void);
void		ft_set_last_index(int index);

void		ft_handle_parent_signal(int signal);
void		ft_ignore_parent_signal(void);
void		ft_handle_child_signal(int signal);
void		ft_register_child_signal(void);
void		ft_register_parent_signal(void);

int			ft_verify_pipe(const char *command, const int index);
int			ft_verify_semicolon(const char *command, const int index);
int			ft_verify_command(const char *command);

void		ft_handle_command(void);
void		ft_exec_commnad(const char *command);
void		ft_trim_command(const char *str, int *index, char *command);
int			ft_get_str_location(const char *str, int *index);
void		ft_route_command(const char *str, int *index);

void		ft_get_env(const char *key, char *value);
void		ft_set_env(const char *key, char *value);
void		ft_delete_env(const char *key);
void		ft_print_env(void);

int			ft_check_dir(const char *str);
void		ft_get_command(const char *str, char *command);
int			ft_get_next_index(const char *str);
void		ft_check_home_dir(char *command);

int			ft_check_last_command(const char *command);
void		ft_join_command(const char *prefix, char *command);

int			ft_suppress_command(const char *str);

int			ft_check_num(const char *str);

int			ft_handle_pwd(const char *command, int *index);
void		ft_return_end(const char *command, int *index);
int			ft_handle_cd(const char *command, int *index);
int			ft_handle_exit(const char *str, int *index);
# define BIN "/bin/"
# define USR_BIN "/usr/bin/"
int			ft_handle_built_in(const char *command, int *index);

char        *ft_change_envs_to_data(const char *str);
char        **ft_get_command_and_data(const char *str);

#endif
