/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_delete_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:56:50 by dakim             #+#    #+#             */
/*   Updated: 2020/08/26 12:03:43 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_delete_env, basic)
{
	char command[1024];
	ft_delete_env("HOME");
	ft_get_env("HOMsfsfsfsfsfsfdE", command);
	cr_expect_eq(*command, 0);
}
