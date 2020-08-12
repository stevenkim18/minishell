/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_trim_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 09:27:32 by dakim             #+#    #+#             */
/*   Updated: 2020/08/12 10:50:55 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_trim_str, basic)
{
	cr_expect_str_eq(ft_trim_str("   123   "), "123");
}
