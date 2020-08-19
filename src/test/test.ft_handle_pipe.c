/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:31:43 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 13:48:39 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_pipe, basic)
{
	ft_open_pipe(ft_get_error_pipe());
	ft_send_int(123, ft_get_error_pipe());
	cr_assert_eq(ft_get_int(ft_get_error_pipe()), 123);
	ft_close_pipe(ft_get_error_pipe());

	ft_open_pipe(ft_get_data_pipe());
	ft_send_str("123", ft_get_data_pipe());
	cr_assert_str_eq(ft_get_str(ft_get_data_pipe()), "123");
	ft_close_pipe(ft_get_data_pipe());

	ft_open_pipe(ft_get_index_pipe());
	ft_send_int(123, ft_get_index_pipe());
	cr_assert_eq(ft_get_int(ft_get_index_pipe()), 123);
	ft_close_pipe(ft_get_index_pipe());
}
