/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:00:59 by dakim             #+#    #+#             */
/*   Updated: 2020/08/21 18:11:33 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_get_env(const char *key, char *value)
{
	extern char		**environ;
	int				i;
	int				j;
	int				k;

	i = -1;
	while (*(environ + ++i))
		if (ft_strnstr(*(environ + i), key, ft_strlen((char *)key)))
			break ;
	j = ft_strlen((char *)key);
	k = 0;
	while (*(*(environ + i) + ++j))
	{
		value[k] = *(*(environ + i) + j);
		++k;
	}
	value[k] = 0;
}
