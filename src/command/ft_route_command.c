/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:27:38 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:43:09 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_trim_str(const char *str)
{
	char	*return_str;

	if (!(return_str = ft_strtrim(str, SPACE_STR)))
		ft_handle_error(ENOMEM, NULL);
	return (return_str);
}

int		ft_exec_command(const char *str)
{
	ft_putstr_fd((char *)str, STDOUT);
	ft_putstr_fd(NEWLINE_STR, STDOUT);
	ft_handle_error(ENOCMD, NULL);
	// while (1)
		// ;
	return (ENOCMD);
}

void		ft_route_command(const char *str)
{
	if (str)
	{
		if (ft_strnstr(str, ECHO_STR, ft_strlen(ECHO_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, CD_STR, ft_strlen(CD_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, PWD_STR, ft_strlen(PWD_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, EXPORT_STR, ft_strlen(EXPORT_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, ENV_STR, ft_strlen(ENV_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, UNSET_STR, ft_strlen(UNSET_STR)))
			ft_exec_process(ft_exec_command, str);
		else if (ft_strnstr(str, EXIT_STR, ft_strlen(EXIT_STR)))
			ft_exec_process(ft_exec_command, str);
		else
			ft_exec_process(ft_exec_command, str);
	}
	else
		ft_handle_error(ENOMEM, NULL);
}
