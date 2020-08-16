/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 15:50:01 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:22:10 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_data, basic)
{
	ft_open_data_pipe();
	ft_send_data("123");
	cr_expect_str_eq(ft_get_data(), "123");
	ft_send_data("123123123123");
	cr_expect_str_eq(ft_get_data(), "123123123123");
	ft_send_data("\\n123");
	cr_expect_str_eq(ft_get_data(), "\\n123");
	ft_send_data("\'123\'");
	cr_expect_str_eq(ft_get_data(), "\'123\'");
	ft_send_data("\"123");
	cr_expect_str_eq(ft_get_data(), "\"123");
	ft_close_data_pipe();
}
