/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 13:23:16 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	ft_putstr_fd(SHELL_STR, STDOUT);
	return (get_next_line(STDOUT, line));
}

static void		ft_handle_command(void)
{
	char		*command;
	char		*tmp_command;
	int			read_result;

	command = NULL;
	read_result = INITIAL_INT;
	while (true)
	{
		read_result = ft_handle_gnl(&command);
		if (0 <= read_result)
		{
			tmp_command = command;
			if (!(command = ft_trim_str(command)))
				ft_handle_error(ENOMEM, EXIT_ERROR, NULL, NULL);
			if (!ft_handle_parsing(command))
				ft_handle_error(-1, NO_EXIT, ENOCMD, command);
			free(tmp_command);
		}
		else if (read_result == -1)
			ft_handle_error(ENOMEM, NO_EXIT, NULL, NULL);
		if (command)
			free(command);
	}
}

int				main()
{
	ft_handle_command();
	return (0);
}
