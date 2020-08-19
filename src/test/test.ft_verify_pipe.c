/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_verify_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:41:42 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 16:25:55 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_verify_pipe, basic)
{
	char *str = "123|;123123|";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123|     ;123123|";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "123;123123|;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "123;123123| ;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "1|23|;123123|";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "1|23|     ;123123|";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "1|23;123123|;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "1|23;123123| ;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	str = "123;123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123|123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123;|123123|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123;     |123123|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123;123123;|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123;123123; |";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "1|23;|123123|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "1|23;     |123123|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "1|23;123123;|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "1|23;123123; |";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123;123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123|123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123123123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
}
