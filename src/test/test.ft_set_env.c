/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_set_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 09:37:19 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 11:30:31 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_set_env, basic)
{
	char command[1024];
	ft_set_env("PWD", "/Users/dakim");
	ft_get_env("PWD", command);
	cr_expect_str_eq(command, "/Users/dakim");
	ft_set_env("123123123123", "werwrwerwer");
	ft_get_env("123123123123", command);
	cr_expect_str_eq(command, "werwrwerwer");

}
