/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:23:46 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/19 15:09:48 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_return_end(const char *command)
{
	int		i;

	i = 0;
	while (command[i])
	{
		if (command[i] == 0 || command[i] == ';' || command[i] == '|')
			return (((char *)command) + i);
		i++;
	}
	return (NULL);
}

int     ft_handle_pwd(const char *command)
{
	char	buff[1024];
	char	*tmp;

	tmp = ft_return_end(command);
	printf("p = %p s = %s\n", tmp, tmp);
	getcwd(buff, 1024);
	ft_putstr_fd(buff, STDOUT);
	ft_putstr_fd("\n", STDOUT);
	return (1);
}
