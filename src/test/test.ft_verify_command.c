/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_verify_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:29:53 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 09:00:04 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_verify_command, basic)
{
	char *str = NULL;
	str = ";123";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "|123";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123|;";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123| ;";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123;|";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123;   |";
	cr_expect_eq(ft_verify_command(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
}
