/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:11:17 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 16:38:56 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_handle_parent_signal(int signal)
{
	if (SIGCHLD == signal)
	{
		ft_put_error(ft_get_int(ft_get_error_pipe()));
		ft_set_index(ft_get_int(ft_get_index_pipe()));
		ft_set_fork_status(false);
	}
	else if ((SIGINT == signal || SIGQUIT == signal))
	{
		ft_putstr_fd(IGNORE_INT, STDOUT);
		if (!ft_get_fork_status())
		{
			if (SIGINT == signal)
			{
				ft_putstr_fd(NEWLINE_STR, STDOUT);
				ft_putstr_fd(SHELL_STR_L, STDOUT);
				ft_put_error(ENOINT_P);
			}
			else
				ft_put_error(NO_ERROR);
		}
	}
}

void			ft_handle_child_signal(int signal)
{
	ft_putstr_fd(IGNORE_INT, STDOUT);
	if (SIGINT == signal)
		ft_end_process(ENOINT, ft_get_last_index(), 0);
	else if (SIGQUIT == signal)
		ft_end_process(ENOQUIT, ft_get_last_index(), ft_get_pid());
	// TODO 두 경우 모두 에러코드 출력 할 수 있도록 해야함
}

void			ft_register_parent_signal(void)
{
	signal(SIGINT, ft_handle_parent_signal);
	signal(SIGCHLD, ft_handle_parent_signal);
	signal(SIGQUIT, ft_handle_parent_signal);
}

void			ft_register_child_signal(void)
{
	signal(SIGINT, ft_handle_child_signal);
	signal(SIGQUIT, ft_handle_child_signal);
}
