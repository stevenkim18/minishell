/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:48:21 by dakim             #+#    #+#             */
/*   Updated: 2020/08/24 16:54:14 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		ft_close_pipe(ft_get_data_pipe());
		ft_close_pipe(ft_get_index_pipe());
		ft_close_pipe(ft_get_error_pipe());
	}
}

void			ft_start_process(pid_t *pid)
{
	int		wait_value;

	ft_open_pipe(ft_get_data_pipe());
	ft_open_pipe(ft_get_index_pipe());
	ft_open_pipe(ft_get_error_pipe());
	*pid = fork();
	wait(&wait_value);
	if (*pid == 0)
		ft_register_child_signal();
}

void			ft_exec_process(int (*ft_exec_command)(const char *, int *),
								const char *command, int *index)
{
	pid_t		pid;
	int			command_result;

	ft_start_process(&pid);
	command_result = 0;
	if (pid == 0)
		command_result = ft_exec_command(command, index);
	ft_end_process(command_result, *index, pid);
}
