/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 13:50:20 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 14:20:53 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_handle_gnl(char **line)
{
	ft_putstr_fd(SHELL_STR_L, STDOUT);
	return (get_next_line(STDOUT, line));
}

char			*ft_trim_str(const char *str)
{
	char	*return_str;

	if (!(return_str = ft_strtrim(str, SPACE_STR)))
		ft_handle_error(ENOMEM, NULL);
	return (return_str);
}

static void		ft_handle_read_result(char **command)
{
	char		*tmp_str;
	int			index;

	index = 0;
	tmp_str = *command;
	if (!(*command = ft_trim_str(*command)))
		ft_handle_error(ENOMEM, NULL);
	ft_exec_command(*command, &index);
	free(tmp_str);
}

void			ft_handle_command(void)
{
	char		*command;
	int			read_result;

	command = NULL;
	read_result = 0;
	while ((read_result = ft_handle_gnl(&command)))
	{
		if (0 < read_result)
			ft_handle_read_result(&command);
		else if (read_result == -1)
			ft_handle_error(ENOMEM, NULL);
		if (command)
			free(command);
	}
	if (read_result == 0)
	{
		ft_putstr_fd(EXIT_STR, STDOUT);
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
	if (command)
		free(command);
}
