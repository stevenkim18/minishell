/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:30:18 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 17:43:29 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			ft_flush_pipe(const char *str)
{
	char		*tmp_str;

	if (*str == '|')
	{
		tmp_str = ft_get_str(ft_get_data_pipe());
		printf("f = %s\n", tmp_str);
		free(tmp_str);
	}
}
