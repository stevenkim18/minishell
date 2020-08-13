/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:15:33 by dakim             #+#    #+#             */
/*   Updated: 2020/08/13 18:43:00 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_get_error_code(const char *error_str)
{
	if (ft_strnstr(error_str, ENOCMD, ft_strlen(ENOCMD)))
		return (ENOCMD_INT);
	return (NO_ERROR);
}

int			ft_handle_error(const int error_num, const int exit_num,
							void *custom_error, void *content)
{
	static int		error_container;
	int				tmp_container;

	tmp_container = error_container;
	ft_putstr_fd(SHELL_STR_S, STDOUT);
	if (0 < error_num)
	{
		error_container = error_num;
		ft_putstr_fd(strerror(error_num), STDOUT);
	}
	if (custom_error)
	{
		error_container = ft_get_error_code(custom_error);
		ft_putstr_fd(custom_error, STDOUT);
	}
	if (content)
		ft_putstr_fd(content, STDOUT);
	ft_putstr_fd(NEWLINE_STR, STDOUT);
	if (exit_num != -1)
		exit(exit_num);
	return (tmp_container);
}
