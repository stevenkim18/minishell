/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:23:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/25 17:39:51 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_return_end(const char *command, int *index)
{
	while (command[*index] && command[*index] != ';' && command[*index] != '|')
		(*index)++;
}

int		ft_handle_pwd(const char *command, int *index)
{
	char	buff[1024];

	ft_return_end(command, index);
	getcwd(buff, 1024);
	if (*(command + *index) == '|')
		ft_send_str(buff, ft_get_data_pipe());
	else
	{
		ft_putstr_fd(buff, STDOUT);
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
	return (NO_ERROR);
}
