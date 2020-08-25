/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_built_in.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 14:25:39 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 17:02:23 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*check_built_in_command(char *path, char *command)
{
	DIR				*dir;
	struct dirent	*file;
	char			*full_command;

	dir = NULL;
	file = NULL;
	full_command = NULL;
	if ((dir = opendir(path)) == NULL)
		return (NULL);
	while ((file = readdir(dir)))
	{
		if (!ft_strncmp(command, file->d_name, ft_strlen(command)))
			break ;
	}
	if (file)
		full_command = ft_strjoin(path, command);
	closedir(dir);
	return (full_command);
}

char		*check_bin_path(char *command)
{
	char	*full_command;

	full_command = NULL;
	if ((full_command = check_built_in_command(BIN, command)))
		return (full_command);
	if ((full_command = check_built_in_command(USR_BIN, command)))
		return (full_command);
	return (NULL);
}
int			ft_handle_built_in_error(const char *command)
{
	char	error_str[1024];

	ft_get_command(command, error_str);
	ft_check_home_dir(error_str);
	if (!ft_check_dir(error_str))
		ft_handle_error(ENODIR, error_str);
	else
		ft_handle_error(ENOCMD, error_str);
	return (ENOCMD);
}

int			ft_handle_built_in(const char *command, int *index)
{
	extern	char	**environ;
	char			*full_command;
	char			**new_arg;

	ft_return_end(command, index);
	if ((full_command = check_bin_path((char *)command)))
	{
		if (!(new_arg = (char **)malloc(sizeof(char*) * (1 + 1))))
			return (ENOMEM);
		new_arg[0] = (char *)command;
		new_arg[1] = NULL;
		ft_send_int(*index, ft_get_index_pipe());
		ft_send_int(NO_ERROR, ft_get_error_pipe());
		execve(full_command, new_arg, environ);
	}
	return (ft_handle_built_in_error(command));
}