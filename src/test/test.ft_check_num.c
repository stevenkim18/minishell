/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_check_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 15:07:05 by dakim             #+#    #+#             */
/*   Updated: 2020/08/27 15:57:21 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_check_num, basic)
{
	char		*str = NULL;

	str = "123123";
	cr_expect_eq(ft_check_num(str), 0);
	str = "123d123";
	cr_expect_eq(ft_check_num(str), -1);
}
