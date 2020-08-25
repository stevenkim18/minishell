/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:59:37 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 16:03:09 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_dir, basic)
{
	char *str = NULL;

	str = "../dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "/dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "./dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "~/dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "~./dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "//dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
	str = "/......./dldldl";
	cr_expect_eq(ft_check_dir(str), 0);
}

