/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_signal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:11:17 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 15:31:21 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_handle_parent_signal(int signal)
{
	if (SIGCHLD == signal)
		ft_put_error(ft_get_pipe());
}

void			ft_handle_child_signal(int signal)
{
	if (SIGINT == signal)
		ft_end_process(ENOINT, 0);
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
