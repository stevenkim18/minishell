/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:07:48 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 12:38:58 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_data_pipe[2];
static int		g_error_pipe[2];
static int		g_index_pipe[2];

int			*ft_get_data_pipe(void)
{
	return (g_data_pipe);
}

int			*ft_get_error_pipe(void)
{
	return (g_error_pipe);
}

int			*ft_get_index_pipe(void)
{
	return (g_index_pipe);
}
