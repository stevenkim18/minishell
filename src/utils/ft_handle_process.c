/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:48:21 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:37:41 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_end_process(const int signal, const pid_t pid)
{
	if (pid == 0)
	{
		ft_send_pipe(signal);
		exit(signal);
	}
	else
		ft_close_pipe();
}

void			ft_start_process(pid_t *pid)
{
	int		wait_value;

	ft_open_pipe();
	*pid = fork();
	wait(&wait_value);
	if (*pid == 0)
		ft_register_child_signal();
}

void			ft_exec_process(int (*ft_exec_command)(const char *),
								const char *command)
{
	pid_t		pid;
	int			command_result;

	ft_start_process(&pid);
	command_result = 0;
	if (pid == 0)
		command_result = ft_exec_command(command);
	ft_end_process(command_result, pid);
}
