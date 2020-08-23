/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 14:26:18 by dakim             #+#    #+#             */
/*   Updated: 2020/08/23 14:32:29 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_command, basic)
{
	char *str = NULL;
	str = "/bin";
	cr_expect_eq(ft_check_command(str), 1);
	str = "./include";
	cr_expect_eq(ft_check_command(str), 1);
	str = "/Users/dakim/Documents";
	cr_expect_eq(ft_check_command(str), 1);
	str = "../ft_services";
	cr_expect_eq(ft_check_command(str), 1);
	str = "/bin/ls";
	cr_expect_eq(ft_check_command(str), 2);
	str = "./a.out";
	cr_expect_eq(ft_check_command(str), 2);
	str = "/Users/dakim/Documents/42/cursus/c1/get_next_line/get_next_line.h";
	cr_expect_eq(ft_check_command(str), 2);
	str = "../minishell/test.out";
	cr_expect_eq(ft_check_command(str), 2);
	str = "1231313123";
	cr_expect_eq(ft_check_command(str), 0);
	str = "ls";
	cr_expect_eq(ft_check_command(str), 0);
}


