/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:06:02 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 16:03:13 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_fd[2];

void			ft_pipe_init(void)
{
	while (true)
	{
		if (-1 != pipe(g_fd))
			break ;
	}
}

void			ft_send_signal(int signal)
{
	ft_putnbr_fd(signal, g_fd[WRITE]);
	ft_putchar_fd('\n', g_fd[WRITE]);
}

int				ft_get_signal(void)
{
	char		*line;
	int			return_value;

	if (-1 == get_next_line(g_fd[READ], &line))
		return (ENOMEM);
	return_value = ft_atoi(line);
	free(line);
	return (return_value);
}
