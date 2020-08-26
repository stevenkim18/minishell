/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_suppress_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 17:47:28 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 17:48:41 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_suppress_command, basic)
{
	cr_expect_eq(ft_suppress_command("|   123   "), -1);
	cr_expect_eq(ft_suppress_command("   123   |"), -1);
	cr_expect_eq(ft_suppress_command("   123   |"), -1);
	cr_expect_eq(ft_suppress_command("   123   "), 0);
}


