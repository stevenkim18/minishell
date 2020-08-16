/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/16 16:34:50 by dakim            ###   ########.fr       */
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
# define NEWLINE_STR "\n"

# define SPACE_STR " "

# define NO_ERROR 0
# define ENOCMD 127
# define ENOINT 130

# define ENOCMD_STR "command not found: "

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);

void	ft_handle_command(void);
void	ft_route_command(const char *str);

# define READ 0
# define WRITE 1

void	ft_end_process(const int signal, const pid_t pid);
void	ft_start_process(pid_t *pid);
void	ft_exec_process(int (*ft_exec_command)(const char *), const char *command);

void	ft_put_error(const int error_num);
int		ft_handle_error(const int error_num, void *content);

void	ft_open_data_pipe(void);
void	ft_close_data_pipe(void);
char	*ft_get_data(void);
void	ft_send_data(char *data);

void	ft_open_pipe(void);
void	ft_close_pipe(void);
void	ft_send_pipe(const int signal);
int		ft_get_pipe(void);

void	ft_handle_parent_signal(int signal);
void	ft_handle_child_signal(int signal);
void	ft_register_parent_signal(void);
void	ft_register_child_signal(void);



#endif
