/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:05:05 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 15:19:14 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_test(const char *str, int *index)
{
	if (*str)
	{
		write(STDOUT, (str + *index), 1);
		++(*index);
		while (*(str + *index)
		&& *(str + *index) != ';' && *(str + *index) != '|')
		{
			write(STDOUT, (str + *index), 1);
			++(*index);
		}
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
	return (ENOCMD);
}

int			ft_check_echo_cd(const char *str, int *index, int i)
{
	*index += i;
	if (ft_strnstr(str + i, ECHO_STR, ft_strlen(ECHO_STR))
	|| ft_strnstr(str + i, ECHO_D, ft_strlen(ECHO_D))
	|| ft_strnstr(str + i, ECHO_S, ft_strlen(ECHO_S)))
	{
		ft_trim_command(str, index, ECHO_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	else if (ft_strnstr(str + i, CD_STR, ft_strlen(CD_STR))
	|| ft_strnstr(str + i, CD_D, ft_strlen(CD_D))
	|| ft_strnstr(str + i, CD_S, ft_strlen(CD_S)))
	{
		ft_trim_command(str, index, CD_STR);
		ft_handle_cd(str, index);
		return (0);
	}
	return (1);
}

int			ft_check_export_env(const char *str, int *index, int i)
{
	*index += i;
	if (ft_strnstr(str + i, EXPORT_STR, ft_strlen(EXPORT_STR))
	|| ft_strnstr(str + i, EXPORT_D, ft_strlen(EXPORT_D))
	|| ft_strnstr(str + i, EXPORT_S, ft_strlen(EXPORT_S)))
	{
		ft_trim_command(str, index, EXPORT_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	else if (ft_strnstr(str + i, ENV_STR, ft_strlen(ENV_STR))
	|| ft_strnstr(str + i, ENV_D, ft_strlen(ENV_D))
	|| ft_strnstr(str + i, ENV_S, ft_strlen(ENV_S)))
	{
		ft_trim_command(str, index, ENV_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	return (1);
}

int			ft_check_pwd_exit_unset(const char *str, int *index, int i)
{
	if (ft_strnstr(str + i, EXIT_STR, ft_strlen(EXIT_STR))
	|| ft_strnstr(str + i, EXIT_D, ft_strlen(EXIT_D))
	|| ft_strnstr(str + i, EXIT_S, ft_strlen(EXIT_S)))
		exit(0);
	else if (ft_strnstr(str + i, PWD_STR, ft_strlen(PWD_STR))
	|| ft_strnstr(str + i, PWD_D, ft_strlen(PWD_D))
	|| ft_strnstr(str + i, PWD_S, ft_strlen(PWD_S)))
	{
		ft_exec_process(ft_handle_pwd, str, index);
		return (0);
	}
	else if (ft_strnstr(str + i, UNSET_STR, ft_strlen(UNSET_STR))
	|| ft_strnstr(str + i, UNSET_D, ft_strlen(UNSET_D))
	|| ft_strnstr(str + i, UNSET_S, ft_strlen(UNSET_S)))
	{
		*index += i;
		ft_trim_command(str, index, UNSET_STR);
		ft_exec_process(ft_test, str, index);
		return (0);
	}
	return (1);
}

void		ft_route_command(const char *str, int *index)
{
	int			i;

	i = 0;
	if (str)
	{
		i = ft_get_str_location(str, index);
		if (!ft_check_echo_cd(str, index, i))
			return ;
		else if (!ft_check_export_env(str, index, i))
			return ;
		else if (!ft_check_pwd_exit_unset(str, index, i))
			return ;
		else
			ft_exec_process(ft_handle_built_in, str, index);
	}
	else
		ft_handle_error(ENOMEM, NULL);
}
