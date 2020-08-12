/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 10:27:01 by dakim            ###   ########.fr       */
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

# define STDOUT 1

# define ECHO_STR "echo"
# define PWD_STR "cd"
# define EXPORT_STR "export"
# define UNSET_STR "unset"
# define ENV_STR "env"
# define EXIT_STR "exit"

# define SPACE_STR " "

# define INITIAL_INT 0
# define ECHO_INT 1
# define PWD_INT 2
# define EXPORT_INT 3
# define UNSET_INT 4
# define ENV_INT 5
# define EXIT_INT 6

int		get_next_line(int fd, char **line);
char	*ft_trim_str(const char *str);

#endif
