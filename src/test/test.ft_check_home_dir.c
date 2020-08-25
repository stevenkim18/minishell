/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_home_dir.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:30:03 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 16:17:37 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_home_dir, basic)
{
	char str[1024];
	str[0] = '~';
	str[1] = '/';
	str[2] = 'b';
	str[3] = 'i';
	str[4] = 'n';
	str[5] = '/';
	str[6] = 'l';
	str[7] = 's';
	str[8] = 0;
	ft_check_home_dir(str);
	cr_expect_str_eq(str, "/Users/dakim/bin/ls");
	str[0] = '~';
	str[1] = 'b';
	str[2] = 'i';
	str[3] = 'n';
	str[4] = '/';
	str[5] = 'l';
	str[6] = 's';
	str[7] = 0;
	ft_check_home_dir(str);
	cr_expect_str_eq(str, "bin/ls");
	str[0] = '~';
	str[1] = '.';
	str[2] = 'b';
	str[3] = 'i';
	str[4] = 'n';
	str[5] = '/';
	str[6] = 'l';
	str[7] = 's';
	str[8] = 0;
	ft_check_home_dir(str);
	cr_expect_str_eq(str, "~.bin/ls");
	str[0] = '.';
	str[1] = '~';
	str[2] = '/';
	str[3] = 'i';
	str[4] = 'n';
	str[5] = '/';
	str[6] = 'l';
	str[7] = 's';
	str[8] = 0;
	ft_check_home_dir(str);
	cr_expect_str_eq(str, ".~/in/ls");
}
