/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 02:33:21 by seunkim           #+#    #+#             */
/*   Updated: 2020/09/02 02:33:36 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_handle_env(const char *command, int *index)
{
    char    **new_arg;
    int     idx;

    ft_return_end(command, index);
    new_arg = ft_get_command_and_data(command);
    idx = 1;
    while (new_arg[idx])
    {
        if (!ft_validate_key_value(new_arg[idx]))
            return (ft_handle_error(ENODIR, new_arg[idx]));
        idx++;
    }
    ft_print_env();
    ft_print_new_envs(new_arg);
    return (NO_ERROR);
}