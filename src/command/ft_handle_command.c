/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:50:20 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:01:37 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	ft_putstr_fd(SHELL_STR_L, STDOUT);
	return (get_next_line(STDOUT, line));
}

void			ft_handle_command(void)
{
	char		*command;
	char		*tmp_command;
	int			read_result;

	command = NULL;
	read_result = INITIAL_INT;
	while ((read_result = ft_handle_gnl(&command)))
	{
		if (0 < read_result)
		{
			tmp_command = command;
			if (!(command = ft_trim_str(command)))
				ft_handle_error(ENOMEM, NULL);
			command = NULL;
			ft_route_command(command);
			free(tmp_command);
		}
		else if (read_result == -1)
			ft_handle_error(ENOMEM, NULL);
		if (command)
			free(command);
	}
	if (command)
		free(command);
}
