/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:03:34 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 12:55:10 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_process, basic)
{
	int		signal;
	pid_t	pid;

	ft_open_pipe();
	signal = ft_start_process(&pid);
	ft_end_process(123, pid);
	cr_expect_eq(signal, 123);
}
