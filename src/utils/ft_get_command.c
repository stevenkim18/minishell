/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 17:24:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 17:24:12 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_get_command(const char *str, char *command)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*(str + i) == ' ')
		++i;
	if (*(str + i) != '\'' && *(str + i) != '\"')
		while (*(str + i) != ' ')
		{
			command[j] = *(str + i++);
			++j;
		}
	else if (*(str + i) == '\"' || *(str + i) == '\'')
	{
		while (*(str + i) == '\'' || *(str + i) == '\"')
			++i;
		while (*(str + i) != '\'' && *(str + i) != '\"')
		{
			command[j] = *(str + i++);
			++j;
		}
	}
	command[j] = 0;
}
