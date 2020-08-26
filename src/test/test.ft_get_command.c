/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_get_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:05:55 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 09:00:33 by dakim            ###   ########.fr       */
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
}
