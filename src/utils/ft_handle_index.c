/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:38:19 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 12:39:02 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_index = 0;

int			ft_get_index(void)
{
	return (g_index);
}

void		ft_set_index(int index)
{
	g_index = index;
}
