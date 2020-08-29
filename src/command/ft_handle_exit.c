/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 17:19:41 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 17:23:10 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_handle_exit_num(const char *str,
					const char *command, int *index)
{
	int			exit_code;
	int			next_index;
	char		next_command[1024];

	next_index = ft_get_next_index(str + *index);
	ft_get_command(str + *index + next_index, next_command);
	if (*next_command)
	{
		ft_handle_error(ENOARGS, "exit");
		ft_return_end(str, index);
		ft_set_index(*index);
		return (0);
	}
	else
	{
		exit_code = ft_atoi((char *)command);
		exit_code %= 256;
		exit(exit_code);
	}
}

int					ft_handle_exit(const char *str, int *index)
{
	char		command[1024];

	ft_get_command(str + *index, command);
	ft_putstr_fd(EXIT_STR, STDOUT);
	ft_putstr_fd(NEWLINE_STR, STDOUT);
	if (ft_check_num(command) || 20 <= ft_strlen(command))
	{
		ft_join_command("exit: ", command);
		ft_handle_error(ENONUMARG, command);
		exit(ENONUMARG);
	}
	else
		return (ft_handle_exit_num(str, command, index));
}
