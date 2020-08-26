/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:39:09 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/26 10:08:29 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_path(const char *command)
{
	char	**argv;
	char	*path;
	int		idx;

	if (!(argv = ft_split(command, ' ')))
		return (NULL);
	idx = 0;
	while (argv[idx])
		idx++;
	if (idx > 1)
	{
		if (!(path = ft_strdup(argv[1])))
			return (NULL);
	}
	else
		path = NULL;
	idx = -1;
	while (argv[++idx])
		free(argv[idx]);
	free(argv);
	return (path);
}

void		ft_handle_cd_error(const char *command)
{
	char	error_str[1024];

	ft_get_command(command, error_str);
	ft_check_home_dir(error_str);
	ft_handle_error(ENODIR, error_str);
}

int		ft_handle_cd(const char *command, int *index)
{
	char	*path;

	if (!(path = ft_get_path(command)))
	{
		ft_handle_error(ENOMEM, NULL);
		return (ENOMEM);
	}
	ft_return_end(command, index);
	if (chdir(path))
	{
		ft_handle_cd_error(path);
		free(path);
		return (ENOCMD);
	}
	free(path);
	return (NO_ERROR);
}
