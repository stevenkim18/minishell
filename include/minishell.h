/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 11:34:08 by dakim            ###   ########.fr       */
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

# define ENOCMD "command not found: "

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);
int		ft_handle_parsing(const char *str);

void		ft_end_process(const int error_num,
						void *custom_error, void *content);

#endif
