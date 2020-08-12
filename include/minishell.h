/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:38 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 09:28:55 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>

# define ECHO_STR "echo"
# define PWD_STR "cd"
# define EXPORT_STR "export"
# define UNSET_STR "unset"
# define ENV_STR "env"
# define EXIT_STR "exit"

# define INITIAL_INT 0
# define ECHO_INT 1
# define PWD_INT 2
# define EXPORT_INT 3
# define UNSET_INT 4
# define ENV_INT 5
# define EXIT_INT 6

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t nelem, size_t elsize);

#endif
