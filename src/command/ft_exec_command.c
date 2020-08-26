/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 14:54:07 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 12:52:58 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_get_str_location(const char *str, int *index)
{
	int			i;

	i = *index;
	if (*(str + i) == ';' || *(str + i) == '|')
		++(i);
	while (*(str + i) == ' ')
		++(i);
	return (i);
}

void			ft_trim_command(const char *str, int *index, char *command)
{
	bool		is_double;
	bool		is_single;

	is_single = false;
	is_double = false;
	if (*str == '\"')
	{
		++(*index);
		is_double = true;
	}
	else if (*str == '\'')
	{
		++(*index);
		is_single = true;
	}
	*index += ft_strlen(command);
	if (*(str + *index) == '\"' && is_double)
		++(*index);
	else if (*(str + *index) == '\'' && is_single)
		++(*index);
	while (*(str + *index) == ' ')
		++(*index);
}

void			ft_exec_commnad(const char *command)
{
	int			index;

	index = ft_get_index();
	ft_route_command(command, &index);
	if (*(command + ft_get_index()))
		ft_exec_commnad(command);
}
