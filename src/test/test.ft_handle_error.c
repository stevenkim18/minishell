/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 18:19:47 by dakim             #+#    #+#             */
/*   Updated: 2020/08/15 17:11:06 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_error, basic)
{
	cr_assert_eq(ft_handle_error(ENOCMD, NULL), 0);
	cr_assert_eq(ft_handle_error(ENOCMD, NULL), ENOCMD);
	cr_assert_eq(ft_handle_error(ENOMEM, NULL), ENOCMD);
	cr_assert_eq(ft_handle_error(ENOMEM, NULL), ENOMEM);

}
