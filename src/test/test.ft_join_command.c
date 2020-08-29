/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_join_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:00:09 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 16:09:26 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_join_command, basic)
{
	char *first = NULL;
	char second[1024];
	first = "exit: ";
	second[0] = 'q';
	second[1] = 'w';
	second[2] = 'e';
	second[3] = 0;
	ft_join_command(first, second);
	cr_assert_str_eq(second, "exit: qwe");
}
