/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:23:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/20 15:29:07 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_return_end(const char *command, int *index)
{
	while (command[*index])
	{
		if (command[*index] == 0 || command[*index] == ';' || command[*index] == '|')
			return ;
		(*index)++;
	}
}

int     ft_handle_pwd(const char *command, int *index)
{
	char	buff[1024];

	write(STDOUT, "1", 1);
	ft_return_end(command, index);
	getcwd(buff, 1024);
	ft_putstr_fd(buff, STDOUT);
	ft_putstr_fd("\n", STDOUT);	
	return (NO_ERROR);
}
