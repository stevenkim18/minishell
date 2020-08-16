/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:04:27 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 13:01:51 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_handle_signal(int signal)
{
	if (SIGINT == signal)
		printf("\nsignal = %d\n", signal);
	else if (SIGCHLD == signal)
		printf("\nend child signal = %d\n", signal);
}

int				main(void)
{
	signal(SIGINT, ft_handle_signal);
	signal(SIGCHLD, ft_handle_signal);
	// ft_open_pipe();
	// ft_handle_command();
	// ft_close_pipe();
	pid_t pid;

	ft_start_process(&pid);
	ft_end_process(128, pid);
	ft_start_process(&pid);
	ft_end_process(128, pid);
	ft_start_process(&pid);
	ft_end_process(128, pid);
	return (0);
}
