/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:07:48 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:18:43 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_data_pipe[2];

void			ft_open_data_pipe(void)
{
	while (true)
	{
		if (-1 != pipe(g_data_pipe))
			break ;
	}
}

void			ft_close_data_pipe(void)
{
	if (g_data_pipe[READ] != STDOUT)
		close(g_data_pipe[READ]);
	if (g_data_pipe[WRITE] != STDIN)
		close(g_data_pipe[WRITE]);
}

void			ft_send_data(char *str)
{
	ft_putstr_fd(str, g_data_pipe[WRITE]);
	ft_putstr_fd(NEWLINE_STR, g_data_pipe[WRITE]);
}

char			*ft_get_data(void)
{
	char		*return_str;

	if (-1 == get_next_line(g_data_pipe[READ], &return_str))
	{
		ft_handle_error(ENOMEM, NULL);
		ft_end_process(ENOMEM, 0);
	}
	return (return_str);
}
