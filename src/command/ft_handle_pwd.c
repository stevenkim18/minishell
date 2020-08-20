/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:23:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/20 16:12:38 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_return_end(const char *command, int *index)
{
	++(*index);
	while (command[*index] && command[*index] != ';' && command[*index] != '|')
		(*index)++;
}

int     ft_handle_pwd(const char *command, int *index)
{
	char	buff[1024];

	ft_return_end(command, index);
	getcwd(buff, 1024);
	ft_putstr_fd(buff, STDOUT);
	ft_putstr_fd(NEWLINE_STR, STDOUT);
	return (NO_ERROR);
}
