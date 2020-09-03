/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_unset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:30:30 by seunkim           #+#    #+#             */
/*   Updated: 2020/09/03 16:30:32 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int     ft_handle_unset(const char *command, int *index)
{
    char    **new_arg;
    int     idx;

    ft_return_end(command, index);
    new_arg = ft_get_command_and_data(command);
    idx = 1;
    while (new_arg[idx])
    {   
        ft_delete_env(new_arg[idx]);
        idx++;
    }
    return (NO_ERROR);
}