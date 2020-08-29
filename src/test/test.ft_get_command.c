/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_get_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:05:55 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 16:49:11 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_get_command, basic)
{
	char command[1024];
	char *str = NULL;
	str = "/bin/ls 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "/bin/ls");
	str = "\'/bin/ls\' 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "/bin/ls");
	str = "\"/bin/ls\" 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "/bin/ls");
	str = "\"/bin/ls    \" 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "/bin/ls    ");
	str = "\"    /bin/ls\" 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "    /bin/ls");
	str = "\"\'\'    /bin/ls\'\'\" 123123";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "    /bin/ls");
	str = "lslsls";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "lslsls");
	str = "lslsls;";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "lslsls");
	str = "lslsls|";
	ft_get_command(str, command);
	cr_expect_str_eq(command, "lslsls");
}

Test(ft_get_next_command, basic)
{
	char *str = NULL;
	str = "/bin/ls /bins/ls";
	cr_expect_str_eq(str + ft_get_next_index(str), " bins/ls");
	str = "\'/bin/ls\' \'/bins/ls\'";
	cr_expect_str_eq(str + ft_get_next_index(str), " \'/bins/ls\'");
	str = "\"/bin/ls\" \"/bins/ls\"";
	cr_expect_str_eq(str + ft_get_next_index(str), " \"/bins/ls\"");
	str = "\"/bin/ls    \" \"/bins/ls    \"";
	cr_expect_str_eq(str + ft_get_next_index(str), " \"/bins/ls    \"");
	str = "\"    /bin/ls\" \"    /bins/ls\"";
	cr_expect_str_eq(str + ft_get_next_index(str), " \"    /bins/ls\"");
	str = "\"\'\'    /bin/ls\'\'\" \"\'\'    /bins/ls\'\'\"";
	cr_expect_str_eq(str + ft_get_next_index(str), " \"\'\'    /bins/ls\'\'\"");
	str = "lslsls";
	cr_expect_str_eq(str + ft_get_next_index(str), "");
	str = "lslsls";
	cr_expect_str_eq(str + ft_get_next_index(str), "");
	str = "lslsls;";
	cr_expect_str_eq(str + ft_get_next_index(str), ";");
	str = "lslsls|";
	cr_expect_str_eq(str + ft_get_next_index(str), "|");
	str = "lslsls lsls";
	cr_expect_str_eq(str + ft_get_next_index(str), " lsls");
	str = "lsls lsls lls";
	cr_expect_str_eq(str + ft_get_next_index(str), " lsls lls");
}
