/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_get_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:59:22 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 11:57:34 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_get_env, basic)
{
	char command[1024];
	ft_get_env("HOME", command);
	cr_expect_str_eq(command, "/Users/dakim");
	ft_get_env("HOMsfsfsfsfsfsfdE", command);
	cr_expect_eq(*command, 0);
}
