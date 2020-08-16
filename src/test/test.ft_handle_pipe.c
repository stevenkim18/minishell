/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_handle_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 14:31:43 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 15:09:01 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

Test(ft_handle_data, basic)
{
	ft_open_pipe();
	ft_send_pipe(123);
	cr_assert_eq(ft_get_pipe(), 123);
	ft_close_pipe();

}
