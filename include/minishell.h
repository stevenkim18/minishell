/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/15 16:01:01 by dakim            ###   ########.fr       */
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

# define ECHO_STR "echo"
# define CD_STR "cd"
# define PWD_STR "pwd"
# define EXPORT_STR "export"
# define ENV_STR "env"
# define UNSET_STR "unset"
# define EXIT_STR "exit"

# define SPACE_STR " "

# define INITIAL_INT 0
# define ECHO_INT 1
# define CD_INT 2
# define PWD_INT 3
# define EXPORT_INT 4
# define ENV_INT 5
# define UNSET_INT 6
# define EXIT_INT 7

# define NO_ERROR 0
# define CUSTOM_ERROR -1
# define EXIT_ERROR 1
# define EXIT_NO_ERROR 0
# define NO_EXIT -1

# define ENOCMD "command not found: "
# define ENOCMD_INT 127

# define SHELL_STR_L "MINISHELL >>"
# define SHELL_STR_S "minishell: "
# define NEWLINE_STR "\n"

#define READ 0
#define WRITE 1

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);

void	ft_handle_command(void);
int		ft_route_command(const char *str);

int		ft_handle_error(const int error_num, const int exit_num,
							void *custom_error, void *content);

void	ft_pipe_init(void);
void	ft_send_signal(int signal);
int		ft_get_signal(void);

void	ft_end_process(int signal, int exit_code);
int		ft_start_process(pid_t *pid);

#endif
