/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:06:02 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 15:47:44 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_pipe[2];

void			ft_open_pipe(void)
{
	while (true)
	{
		if (-1 != pipe(g_pipe))
			break ;
	}
}

void			ft_close_pipe(void)
{
	if (g_pipe[READ] != STDOUT)
		close(g_pipe[READ]);
	if (g_pipe[WRITE] != STDIN)
		close(g_pipe[WRITE]);
}

void			ft_send_pipe(const int signal)
{
	ft_putnbr_fd(signal, g_pipe[WRITE]);
}

int				ft_get_pipe(void)
{
	char		buffer[100];
	int			read_result;
	int			return_value;

	read_result = read(g_pipe[READ], buffer, 100);
	buffer[read_result] = 0;
	return_value = ft_atoi(buffer);
	return (return_value);
}
