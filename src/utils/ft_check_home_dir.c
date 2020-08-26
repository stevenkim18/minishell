/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_home_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:22:40 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 10:32:49 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_add_home_dir(char *command)
{
	char	dir[1024];
	int		i;
	int		j;

	j = 0;
	i = 0;
	ft_get_env("HOME", dir);
	while (*(dir + i))
		++i;
	while (*(command + ++j))
		dir[i++] = command[j];
	dir[i] = 0;
	i = -1;
	j = 0;
	while (*(dir + ++i))
		command[j++] = dir[i];
	command[j] = 0;
}

void		ft_check_home_dir(char *command)
{
	if (*command == '~')
	{
		if (*(command + 1) == '/')
			ft_add_home_dir(command);
	}
}
