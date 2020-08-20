/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:50 by dakim             #+#    #+#             */
/*   Updated: 2020/08/20 16:37:38 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int			ft_verify_pipe(const char *command, const int index)
{
	int		i;

	i = index;
	if (*(command + i) == '|')
	{
		if (i == 0)
		{
			ft_handle_error(ENOTKN, ENOTKN_P);
			return (ENOTKN);
		}
		else
		{
			++i;
			while (*(command + i) == ' ')
				++i;
			if (*(command + i) == ';')
			{
				ft_handle_error(ENOTKN, ENOTKN_S);
				return (ENOTKN);
			}
		}
	}
	return (NO_ERROR);
}

int			ft_verify_semicolon(const char *command, const int index)
{
	int			i;

	i = index;
	if (*(command + i) == ';')
	{
		if (i == 0)
		{
			ft_handle_error(ENOTKN, ENOTKN_S);
			return (ENOTKN);
		}
		else
		{
			++i;
			while (*(command + i) == ' ')
				++i;
			if (*(command + i) == '|')
			{
				ft_handle_error(ENOTKN, ENOTKN_P);
				return (ENOTKN);
			}
		}
	}
	return (NO_ERROR);
}

int			ft_verify_command(const char *command)
{
	int		index;

	index = -1;
	while (*(command + ++index))
	{
		if (ENOTKN == ft_verify_semicolon(command, index))
			return (ENOTKN);
		else if ((ENOTKN == ft_verify_pipe(command, index)))
			return (ENOTKN);
	}
	return (NO_ERROR);
}
