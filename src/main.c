/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:04:27 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 15:27:00 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				main(void)
{
	ft_register_parent_signal();

	pid_t pid;

	ft_start_process(&pid);
	if (pid == 0)
	{
		printf("child\n");
		while (1)
			;

	}
	else
	{
		printf("parent\n");
		while (1)
			;
	}

	ft_handle_command();
	return (0);
}
