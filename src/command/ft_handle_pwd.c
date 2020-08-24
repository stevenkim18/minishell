/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:23:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/24 16:53:27 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_return_end(const char *command, int *index)
{
	if (*command)
	{
		++(*index);
		while (command[*index]
		&& command[*index] != ';' && command[*index] != '|')
			(*index)++;
		ft_set_index(*index);
	}
}

int		ft_handle_pwd(const char *command, int *index)
{
	char	buff[1024];

	ft_return_end(command, index);
	getcwd(buff, 1024);
	ft_putstr_fd(buff, STDOUT);
	ft_putstr_fd(NEWLINE_STR, STDOUT);
	return (NO_ERROR);
}
