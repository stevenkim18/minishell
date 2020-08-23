/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:01:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/23 14:41:32 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** 1. get command
** 2. check command kind
** 3. execute command
*/

void		ft_get_command(const char *str, char *command)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*(str + i) == ' ')
		++i;
	if (*(str + i) != '\'' && *(str + i) != '\"')
		while (*(str + i) != ' ')
		{
			command[j] = *(str + i++);
			++j;
		}
	else if (*(str + i) == '\"' || *(str + i) == '\'')
	{
		while (*(str + i) == '\'' || *(str + i) == '\"')
			++i;
		while (*(str + i) != '\'' && *(str + i) != '\"')
		{
			command[j] = *(str + i++);
			++j;
		}
	}
	command[j] = 0;
}

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

static void	ft_remove_home_dir(char *command)
{
	char	dir[1024];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(command + ++i))
		dir[j++] = command[i];
	dir[j] = 0;
	j = -1;
	i = 0;
	while (*(dir + ++j))
		command[i++] = dir[j];
	command[i] = 0;
}

void		ft_check_home_dir(char *command)
{
	if (*command == '~')
	{
		if (*(command + 1) == '/')
			ft_add_home_dir(command);
		else
			ft_remove_home_dir(command);
	}
}

int			ft_check_command(char *command)
{
	struct stat		command_info;
	if (!stat(command, &command_info))
	{
		if (S_ISREG(command_info.st_mode))
			return (FILE);
		else if (S_ISDIR(command_info.st_mode))
			return (DIR);
	}
	return (ERROR);
}
