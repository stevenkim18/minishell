/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 16:33:17 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 17:10:37 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
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
	if (error_num < 0 && !custom_error)
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
	if (!(error_num <= 0 && !custom_error))
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	if (exit_num != -1)
		exit(exit_num);
	return (tmp_container);
}
*/
static bool	ft_check_error(const int error_num)
{
	if (error_num == NO_ERROR)
		return (false);
	return (true);
}

static bool	ft_chcek_custom_error(const int error_num)
{
	if (error_num == ENOCMD)
		return (true);
	return (false);
}

static void	ft_print_custom_error(const int error_num)
{
	if (error_num == ENOCMD)
		ft_putstr_fd(ENOCMD_STR, STDOUT);
}

int			ft_handle_error(const int error_num, void *content)
{
	static int		error_container;
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
	tmp_container = error_container;
	error_container = error_num;
	return (tmp_container);
}
