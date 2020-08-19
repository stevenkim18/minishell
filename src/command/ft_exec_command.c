/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:27:38 by dakim             #+#    #+#             */
/*   Updated: 2020/08/17 15:16:15 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_test(const char *str, int *index)
{
	if (*str)
	{
		write(STDOUT, (str + *index), 1);
		ft_putstr_fd(NEWLINE_STR, STDOUT);
		++(*index);
	}
	return (ENOCMD);
}

void		ft_exec_command(const char *str, int *index)
{
	if (str)
	{
		if (ft_strnstr(str, ECHO_STR, ft_strlen(ECHO_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, CD_STR, ft_strlen(CD_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, PWD_STR, ft_strlen(PWD_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, EXPORT_STR, ft_strlen(EXPORT_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, ENV_STR, ft_strlen(ENV_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, UNSET_STR, ft_strlen(UNSET_STR)))
			ft_exec_process(ft_test, str, index);
		else if (ft_strnstr(str, EXIT_STR, ft_strlen(EXIT_STR)))
			ft_exec_process(ft_test, str, index);
		else
			ft_exec_process(ft_test, str, index);
	}
	else
		ft_handle_error(ENOMEM, NULL);
}
