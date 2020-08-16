/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_route_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:12:23 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 13:32:40 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_route_command, basic)
{
	cr_assert_eq(ft_route_command("echo  sdfs"), ECHO_INT);
	cr_assert_eq(ft_route_command("cd  sdfs"), CD_INT);
	cr_assert_eq(ft_route_command("pwd  sdfs"), PWD_INT);
	cr_assert_eq(ft_route_command("export  sdfs"), EXPORT_INT);
	cr_assert_eq(ft_route_command("env  sdfs"), ENV_INT);
	cr_assert_eq(ft_route_command("unset  sdfs"), UNSET_INT);
	cr_assert_eq(ft_route_command("exit  sdfs"), EXIT_INT);
	cr_assert_eq(ft_route_command("eco exit  sdfs"), INITIAL_INT);
}
