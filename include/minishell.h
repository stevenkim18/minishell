/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/16 12:59:43 by dakim            ###   ########.fr       */
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

# define INITIAL_INT 0
# define ECHO_INT 1
# define CD_INT 2
# define PWD_INT 3
# define EXPORT_INT 4
# define ENV_INT 5
# define UNSET_INT 6
# define EXIT_INT 7

# define NO_ERROR 0
# define ENOCMD 127

# define ENOCMD_STR "command not found: "

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);

void	ft_handle_command(void);
int		ft_route_command(const char *str);

#define READ 0
#define WRITE 1

void	ft_end_process(const int signal, const pid_t pid);
int		ft_start_process(pid_t *pid);

int		ft_handle_error(const int error_num, void *content);

#endif
