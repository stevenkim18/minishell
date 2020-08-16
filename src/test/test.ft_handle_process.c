/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 15:03:34 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 13:32:53 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_process, basic)
{
	int		signal;
	pid_t	pid;

	signal = ft_start_process(&pid);
	ft_end_process(123, pid);
	cr_expect_eq(signal, 123);
	signal = ft_start_process(&pid);
	ft_end_process(122, pid);
	cr_expect_eq(signal, 122);
	signal = ft_start_process(&pid);
	ft_end_process(222, pid);
	cr_expect_eq(signal,222);
}
