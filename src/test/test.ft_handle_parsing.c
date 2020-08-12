/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:12:23 by dakim             #+#    #+#             */
/*   Updated: 2020/08/12 15:27:14 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_parsing, basic)
{
	cr_assert_eq(ft_handle_parsing("echo  sdfs"), ECHO_INT);
	cr_assert_eq(ft_handle_parsing("cd  sdfs"), CD_INT);
	cr_assert_eq(ft_handle_parsing("pwd  sdfs"), PWD_INT);
	cr_assert_eq(ft_handle_parsing("export  sdfs"), EXPORT_INT);
	cr_assert_eq(ft_handle_parsing("env  sdfs"), ENV_INT);
	cr_assert_eq(ft_handle_parsing("unset  sdfs"), UNSET_INT);
	cr_assert_eq(ft_handle_parsing("exit  sdfs"), EXIT_INT);
	cr_assert_eq(ft_handle_parsing("eco exit  sdfs"), INITIAL_INT);
}
