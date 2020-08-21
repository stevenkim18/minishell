/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_home_dir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:30:03 by dakim             #+#    #+#             */
/*   Updated: 2020/08/21 17:32:06 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_home_dir, basic)
{
	char command[1024];
	char *str = NULL;
	str = "~/bin/ls";
	ft_check_home_dir(str, command);
	cr_expect_str_eq(command, "/Users/dakim/bin/ls");
	str = "~bin/ls";
	ft_check_home_dir(str, command);
	cr_expect_str_eq(command, "bin/ls");
}
