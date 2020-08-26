/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:48:21 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 16:38:24 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static pid_t	g_pid = 0;

pid_t			ft_get_pid(void)
{
	return (g_pid);
}

void			ft_end_process(const int error, int index, const pid_t pid)
{
	if (pid == 0)
	{
		ft_send_int(error, ft_get_error_pipe());
		ft_send_int(index, ft_get_index_pipe());
		exit(error);
	}
	else
	{
		ft_close_pipe(ft_get_index_pipe());
		ft_close_pipe(ft_get_error_pipe());
	}
}

void			ft_start_process(pid_t *pid)
{
	int		wait_value;

	ft_open_pipe(ft_get_index_pipe());
	ft_open_pipe(ft_get_error_pipe());
	ft_set_fork_status(true);
	*pid = fork();
	wait(&wait_value);
	if (*pid == 0)
		ft_register_child_signal();
}

void			ft_exec_process(int (*ft_exec_command)(const char *, int *),
								const char *command, int *index)
{
	int			command_result;

	ft_start_process(&g_pid);
	command_result = 0;
	if (g_pid == 0)
		command_result = ft_exec_command(command, index);
	ft_end_process(command_result, *index, g_pid);
}
