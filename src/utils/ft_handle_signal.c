/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:11:17 by dakim             #+#    #+#             */
/*   Updated: 2020/08/20 13:59:43 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_handle_parent_signal(int signal)
{
	if (SIGCHLD == signal)
	{
		ft_put_error(ft_get_int(ft_get_error_pipe()));
		ft_set_index(ft_get_int(ft_get_index_pipe()));
		ft_putstr_fd("end process\n", STDOUT);
	}
	else if (SIGINT == signal || SIGQUIT == signal)
	{
		ft_putstr_fd("\b\b  \b\b", STDOUT);
		if (SIGINT == signal)
		{
			ft_putstr_fd(NEWLINE_STR, STDOUT);
			ft_putstr_fd(SHELL_STR_L, STDOUT);
			ft_put_error(ENOINT_P);
		}
	}
}

void			ft_handle_child_signal(int signal)
{
	if (SIGINT == signal)
		ft_end_process(ENOINT, 0, 0);
}

void			ft_register_parent_signal(void)
{
	signal(SIGINT, ft_handle_parent_signal);
	signal(SIGCHLD, ft_handle_parent_signal);
}

void			ft_register_child_signal(void)
{
	signal(SIGINT, ft_handle_child_signal);
}
