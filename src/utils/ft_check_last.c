/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:16:41 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 17:20:35 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_check_last(const char *command)
{
	if (*command == '|' && *(command + 1) == 0)
		return (-1);
	else if (*command == ';' && *(command + 1) == 0)
		return (-1);
	else if (*command == 0)
		return (-1);
	return (0);
}
