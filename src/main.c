/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:04:27 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 12:06:45 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(void)
{
	ft_open_pipe();

	pid_t pid;

	ft_start_process(&pid);
	while (1)
		;
	ft_handle_command();
	ft_close_pipe();
	return (0);
}
