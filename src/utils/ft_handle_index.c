/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:10:51 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 13:18:15 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			g_index_pipe[2];

void				ft_open_index_pipe(void)
{
	while (true)
	{
		if (-1 != pipe(g_index_pipe))
			break ;
	}
}

void				ft_close_index_pipe(void)
{
	if (g_index_pipe[READ] != STDOUT)
		close(g_index_pipe[READ]);
	if (g_index_pipe[WRITE] != STDIN)
		close(g_index_pipe[WRITE]);
}

void				ft_send_index(const int index)
{
	ft_putnbr_fd(index, g_index_pipe[WRITE]);
}

int					ft_get_index(void)
{
	char			buffer[100];
	int				read_result;
	int				return_value;

	read_result = read(g_index_pipe[READ], buffer, 100);
	buffer[read_result] = 0;
	return_value = ft_atoi(buffer);
	return (return_value);
}

