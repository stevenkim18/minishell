/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:06:02 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 13:29:29 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_open_pipe(int fd[2])
{
	while (true)
	{
		if (-1 != pipe(fd))
			break ;
	}
}

void			ft_close_pipe(int fd[2])
{
	if (fd[READ] != STDOUT)
		close(fd[READ]);
	if (fd[WRITE] != STDIN)
		close(fd[WRITE]);
}
