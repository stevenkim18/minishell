/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_get_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:32:52 by dakim             #+#    #+#             */
/*   Updated: 2020/08/21 16:10:32 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_get_char, basic)
{
	char *str = "123;123123|";
	cr_expect_str_eq(ft_strnstr(str, ";", ft_strlen(str)), ";123123|");
	cr_expect_str_eq(ft_strnstr(str, "|", ft_strlen(str)), "|");
}
