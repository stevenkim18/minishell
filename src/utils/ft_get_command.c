/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:24:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 15:56:28 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_get_command(const char *str, char *command)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*(str + i) && (*(str + i) == '|' || *(str + i) == ';'))
		++i;
	while (*(str + i) && *(str + i) == ' ')
		++i;
	if (*(str + i) && (*(str + i) == '\'' || *(str + i) == '\"'))
	{
		while (*(str + i) && (*(str + i) == '\'' || *(str + i) == '\"'))
			++i;
		while (*(str + i) && j < 1023
		&& (*(str + i) != '\'' && *(str + i) != '\"'))
			command[j++] = *(str + i++);
	}
	else
	{
		while (*(str + i) && j < 1023
		&& (*(str + i) != '\'' && *(str + i) != '\"' && *(str + i) != ' '))
			command[j++] = *(str + i++);
	}
	command[j] = 0;
}
