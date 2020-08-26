/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:12:23 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 17:16:10 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_last_command, basic)
{
	char command[1024];
	command[0] = ';';
	command[1] = 0;
	cr_expect_eq(ft_check_last_command(command), -1);
	command[0] = '|';
	command[1] = 0;
	cr_expect_eq(ft_check_last_command(command), -1);
	command[0] = 0;
	cr_expect_eq(ft_check_last_command(command), -1);
}
