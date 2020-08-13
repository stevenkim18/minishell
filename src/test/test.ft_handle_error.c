/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:19:47 by dakim             #+#    #+#             */
/*   Updated: 2020/08/13 18:44:21 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_error, basic)
{
	cr_assert_eq(ft_handle_error(CUSTOM_ERROR, NO_EXIT, ENOCMD, NULL), 0);
	cr_assert_eq(ft_handle_error(CUSTOM_ERROR, NO_EXIT, ENOCMD, NULL), ENOCMD_INT);
	cr_assert_eq(ft_handle_error(CUSTOM_ERROR, NO_EXIT, ENOCMD, NULL), ENOCMD_INT);
}
