/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:48:21 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 16:51:28 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_end_process(const int signal)
{
	ft_send_signal(signal);
	exit(signal);
}

int			ft_start_process(pid_t *pid)
{
	int		wait_value;
	int		return_value;

	*pid = fork();
	wait(&wait_value);
	return_value = 0;
	if (*pid != 0)
		return_value = ft_get_signal();
	return (return_value);
}
