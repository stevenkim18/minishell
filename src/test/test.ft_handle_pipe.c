/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:31:43 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 13:31:46 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_pipe, basic)
{
	int fd[2];
	ft_open_pipe(fd);
	ft_send_int(123, fd);
	cr_assert_eq(ft_get_int(fd), 123);
	ft_send_str("123", fd);
	cr_assert_str_eq(ft_get_str(fd), "123");
	ft_close_pipe(fd);
}
