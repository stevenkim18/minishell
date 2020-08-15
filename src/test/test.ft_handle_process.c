/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:03:34 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 16:04:24 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_process, basic)
{
	int		signal;
	pid_t	pid;

	ft_pipe_init();
	signal = ft_start_process(&pid);
	if (pid == 0)
	{
		ft_end_process(123, 0);
	}
	else
	{
		cr_expect_eq(signal, 123);
	}

}
