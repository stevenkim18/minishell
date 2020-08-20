/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 13:29:08 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 14:55:26 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_send_int(const int signal, int fd[2])
{
	ft_putnbr_fd(signal, fd[WRITE]);
}

int				ft_get_int(int fd[2])
{
	char		buffer[100];
	int			read_result;
	int			return_value;

	read_result = read(fd[READ], buffer, 100);
	buffer[read_result] = 0;
	return_value = ft_atoi(buffer);
	return (return_value);
}

void			ft_send_str(char *str, int fd[2])
{
	ft_putstr_fd(str, fd[WRITE]);
	ft_putstr_fd(NEWLINE_STR, fd[WRITE]);
}

char			*ft_get_str(int fd[2])
{
	char		*return_str;

	if (-1 == get_next_line(fd[READ], &return_str))
	{
		ft_handle_error(ENOMEM, NULL);
		ft_end_process(ENOMEM, 0, ft_get_index());
	}
	return (return_str);
}
