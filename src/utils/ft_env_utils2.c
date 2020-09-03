/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:09:27 by seunkim           #+#    #+#             */
/*   Updated: 2020/09/03 16:09:29 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_add_new_env(char *new_arg)
{
    extern char     **environ;
    int             i;

    i = 0;
    while (environ[i])
        i++;
    environ[i] = new_arg;
    i++;
    environ[i] = 0;
}

void    ft_add_envs(char *new_arg)
{
    int     i;
    int     j;
    char    key[1024];
    char    value[1024];
    char    new_value[1024];

    i = -1;
    j = 0;
    while (new_arg[++i] && new_arg[i] != '=')
        key[j++] = new_arg[i];
    key[j] = 0;
    j = 0;
    while (new_arg[++i])
        new_value[j++] = new_arg[i];
    new_value[j] = 0;
    ft_get_env(key, value);
    if (value[0] == 0)
        ft_add_new_env(new_arg);
    else
        ft_set_env(key, new_value);
}

void    ft_print_new_envs(char **new_arg)
{
    int     idx;

    idx = 1;
    while (new_arg[idx])
    {
        ft_putstr_fd(new_arg[idx], STDOUT);
        ft_putchar_fd('\n', STDOUT);
        idx++;
    }
}

int     ft_validate_key_value(char *arg)
{
    int     idx;

    idx = 0;
    while (arg[idx])
    {   
        if (arg[idx] == '=')
            return (1);
        idx++;
    }
    return (0);
}
