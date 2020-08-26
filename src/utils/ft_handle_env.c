/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:00:59 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 11:31:08 by dakim            ###   ########.fr       */
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
	k = 0;
	while (*(environ + ++i))
		if (ft_strnstr(*(environ + i), key, ft_strlen((char *)key)))
			break ;
	if (*(environ + i))
	{
		j = ft_strlen((char *)key);
		while (*(*(environ + i) + ++j))
		{
			value[k] = *(*(environ + i) + j);
			++k;
		}
	}
	value[k] = 0;
}

void		ft_set_env(const char *key, char *value)
{
	int					i;
	extern char			**environ;
	char				*modify_str;
	char				*tmp_str;

	i = -1;
	tmp_str = NULL;
	modify_str = NULL;
	while (*(environ + ++i))
		if (ft_strnstr(*(environ + i), key, ft_strlen((char *)key)))
			break ;
	if (!(modify_str = ft_strjoin(key, "=")))
	{
		ft_handle_error(ENOMEM, NULL);
		return ;
	}
	tmp_str = modify_str;
	if (!(modify_str = ft_strjoin(modify_str, value)))
	{
		free(tmp_str);
		ft_handle_error(ENOMEM, NULL);
		return ;
	}
	free(tmp_str);
	*(environ + i) = modify_str;
}
