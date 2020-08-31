/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 23:26:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/09/01 01:16:18 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_print_args(char **args, int idx)
{
    int     is_newline;

    if (idx == 1)
        is_newline = 1;
    else if (idx == 2)
        is_newline = 0;
    
    while (args[idx])
    {
        ft_putstr_fd(args[idx], STDOUT);
        ft_putchar_fd(' ', STDOUT);
        idx++;
    }
    if (is_newline)
        ft_putchar_fd('\n', STDOUT);
}

int     ft_handle_echo(const char *command, int *index)
{
    char    **args;
    int     idx;

    ft_return_end(command, index);
    args = ft_get_command_and_data(command);
    if (args[1] == 0)
    {
        ft_putchar_fd('\n', STDOUT);
        return (NO_ERROR);
    }
    idx = 1;
    if (!ft_strncmp(args[idx], "-n", 2))
        idx++;
    ft_print_args(args, idx);
    return (NO_ERROR);
}


