/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:33:17 by dakim             #+#    #+#             */
/*   Updated: 2020/08/17 15:16:38 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		g_error_num;

static bool		ft_check_error(const int error_num)
{
	if (error_num == NO_ERROR)
		return (false);
	return (true);
}

static bool		ft_chcek_custom_error(const int error_num)
{
	if (error_num == ENOCMD)
		return (true);
	return (false);
}

static void		ft_print_custom_error(const int error_num)
{
	if (error_num == ENOCMD)
		ft_putstr_fd(ENOCMD_STR, STDOUT);
}

void			ft_put_error(const int error_num)
{
	g_error_num = error_num;
}

int				ft_handle_error(const int error_num, void *content)
{
	int				tmp_container;

	if (ft_check_error(error_num))
	{
		ft_putstr_fd(SHELL_STR_S, STDOUT);
		if (ft_chcek_custom_error(error_num))
		{
			ft_print_custom_error(error_num);
			if (content)
				ft_putstr_fd(content, STDOUT);
		}
		else
			ft_putstr_fd(strerror(error_num), STDOUT);
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
	tmp_container = g_error_num;
	g_error_num = error_num;
	return (tmp_container);
}
