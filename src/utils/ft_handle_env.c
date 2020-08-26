/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 18:00:59 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 09:51:55 by dakim            ###   ########.fr       */
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
/*
void		ft_set_env(const char *key, char *value)
{
	extern char			*environ;
	int					i;

	i = -1;
	while (*(environ + ++i))
		if (ft_strnstr(*(environ + i), key, ft_strlen((char *)key)))
			break ;

}

int main()
{
	char pwd[1024];
	char old_pwd[1024];
	ft_get_env("PWD", pwd);
	ft_get_env("OLDPWD", old_pwd);
	printf("pwd = %s\n", pwd);
	printf("old_pwd = %s\n", old_pwd);
	chdir("../");
	ft_get_env("PWD", pwd);
	ft_get_env("OLDPWD", old_pwd);
	printf("pwd = %s\n", pwd);
	printf("old_pwd = %s\n", old_pwd);

}
*/
