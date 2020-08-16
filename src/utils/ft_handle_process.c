/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:48:21 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 13:16:54 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_signal_pipe[2];

static void		ft_open_pipe(void)
{
	while (true)
	{
		if (-1 != pipe(g_signal_pipe))
			break ;
	}
}

static void		ft_close_pipe(void)
{
	if (g_signal_pipe[READ] != STDOUT)
		close(g_signal_pipe[READ]);
	if (g_signal_pipe[WRITE] != STDIN)
		close(g_signal_pipe[WRITE]);
}

static void		ft_send_signal(const int signal)
{
	ft_putnbr_fd(signal, g_signal_pipe[WRITE]);
}

static int		ft_get_signal(void)
{
	char		buffer[100];
	int			read_result;
	int			return_value;

	read_result = read(g_signal_pipe[READ], buffer, 100);
	buffer[read_result] = 0;
	return_value = ft_atoi(buffer);
	return (return_value);
}

void			ft_end_process(const int signal, const pid_t pid)
{
	if (pid == 0)
	{
		ft_send_signal(signal);
		exit(signal);
	}
	else
		ft_close_pipe();
}

int				ft_start_process(pid_t *pid)
{
	int		wait_value;
	int		return_value;

	ft_open_pipe();
	*pid = fork();
	wait(&wait_value);
	return_value = 0;
	if (*pid != 0)
		return_value = ft_get_signal();
	return (return_value);
}
