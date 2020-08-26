/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_suppress_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:46:58 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 18:14:13 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_suppress_command(const char *str)
{
	int		i;

	i = 0;
	if (*(str + i) == '|')
		return (-1);
	++i;
	ft_return_end(str, &i);
	if (*(str + i) == '|')
		return (-1);
	return (0);
}
