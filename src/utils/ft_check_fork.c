/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:34:37 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 16:36:48 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool		g_is_fork = false;

bool			ft_get_fork_status(void)
{
	return (g_is_fork);
}

void			ft_set_fork_status(bool status)
{
	g_is_fork = status;
}
