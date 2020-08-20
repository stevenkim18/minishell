/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:54:07 by dakim             #+#    #+#             */
/*   Updated: 2020/08/20 16:18:46 by dakim            ###   ########.fr       */
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

static int		ft_get_str_location(const char *str, int *index)
{
	int			i;

	i = *index;
	if (*(str + i) == ';' || *(str + i) == '|')
		++i;
	while (*(str + i) == ' ')
		++i;
	return (i);
}

static void		ft_route_command(const char *str, int *index)
{
	int			i;

	i = 0;
	if (str)
	{
		i = ft_get_str_location(str, index);
		if (ft_strnstr(str + i, ECHO_STR, ft_strlen(ECHO_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + i, CD_STR, ft_strlen(CD_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + i, PWD_STR, ft_strlen(PWD_STR)))
			ft_exec_process(ft_handle_pwd, str, index);
		else if (ft_strnstr(str + i, EXPORT_STR, ft_strlen(EXPORT_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + i, ENV_STR, ft_strlen(ENV_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + i, UNSET_STR, ft_strlen(UNSET_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + i, EXIT_STR, ft_strlen(EXIT_STR)))
		{
			exit(0);
		}
		else
			ft_exec_process(ft_test, str, index);
	}
	else
		ft_handle_error(ENOMEM, NULL);
}

void			ft_exec_commnad(const char *command)
{
	int			index;

	index = ft_get_index();
	ft_route_command(command, &index);
	if (*(command + ft_get_index()))
		ft_exec_commnad(command);
}
