/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:39:09 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/27 17:25:47 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_handle_cd(const char *command, int *index)
{
	char		dir[1024];
	char		path[1024];
	ft_get_command(command + *index, dir);
	ft_check_home_dir(dir);
	ft_return_end(command, index);
	if (!*dir)
		ft_get_env("HOME", dir);
	getcwd(path, 1024);
	ft_set_env("OLDPWD", path);
	if (chdir(dir))
	{
		ft_handle_error(ENODIR, dir);
		return (ENODIR);
	}
	getcwd(path, 1024);
	ft_set_env("PWD", path);
	return (NO_ERROR);
}
