/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:04:12 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 16:10:47 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_join_command(const char *prefix, char *command)
{
	int			i;
	int			j;
	char		tmp_command[1024];

	i = -1;
	while (command[++i])
		tmp_command[i] = command[i];
	tmp_command[i] = 0;
	i = -1;
	while (*(prefix + ++i) && i < 1023)
		command[i] = *(prefix + i);
	j = -1;
	while (tmp_command[++j] && i < 1023)
		command[i++] = tmp_command[j];
	command[i] = 0;
}
