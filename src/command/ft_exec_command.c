/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:54:07 by dakim             #+#    #+#             */
/*   Updated: 2020/08/20 15:45:15 by dakim            ###   ########.fr       */
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

static void		ft_route_command(const char *str, int *index)
{
	if (str)
	{
		if (ft_strnstr(str + *index, ECHO_STR, ft_strlen(ECHO_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + *index, CD_STR, ft_strlen(CD_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + *index, PWD_STR, ft_strlen(PWD_STR)))
			ft_exec_process(ft_handle_pwd, str, index);
		else if (ft_strnstr(str + *index, EXPORT_STR, ft_strlen(EXPORT_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + *index, ENV_STR, ft_strlen(ENV_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + *index, UNSET_STR, ft_strlen(UNSET_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str + *index, EXIT_STR, ft_strlen(EXIT_STR)))
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
