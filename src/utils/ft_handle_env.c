/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:00:59 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 12:02:28 by dakim            ###   ########.fr       */
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

void		ft_delete_env(const char *key)
{
	int					i;
	extern char			**environ;

	i = -1;
	while (*(environ + ++i))
		if (ft_strnstr(*(environ + i), key, ft_strlen((char *)key)))
			break ;
	while (*(environ + i))
	{
		*(environ + i) = *(environ + i + 1);
		++i;
	}
}

void		ft_print_env(void)
{
	int					i;
	extern char			**environ;

	i = -1;
	while (*(environ + ++i))
	{
		ft_putstr_fd(*(environ + i), STDOUT);
		ft_putstr_fd(NEWLINE_STR, STDOUT);
	}
}
