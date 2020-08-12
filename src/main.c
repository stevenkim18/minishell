/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/12 12:57:17 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	ft_putstr_fd("MINISHELL >>", STDOUT);
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
				ft_handle_error(ENOMEM, EXIT_ERROR, NULL, NEWLINE_STR);
			free(tmp_command);
			printf("|%s|\n", command);
		}
		else if (read_result == -1)
			ft_handle_error(ENOMEM, NO_EXIT, NULL, NEWLINE_STR);
		if (command)
			free(command);
	}
}

int				main()
{
	ft_handle_command();
	return (0);
}
