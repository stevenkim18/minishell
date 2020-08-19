/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.ft_verify_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:41:42 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 16:43:34 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <criterion/criterion.h>

/*
** 1. |; error
** 2. | ; error
** 7. ;123|; error
** 8. ;123| ; error
** 9. |123 no_error
** 10. 123 no_error
** 3. ;| no_error
** 4. ; | no_error
** 5. |123|; no_error
** 6. |123| ; no_error
**
*/

Test(ft_verify_pipe, basic)
{
	char *str = NULL;
	str = "123|;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "123| ;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = ";123|;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = ";123| ;";
	cr_expect_eq(ft_verify_pipe(str), ENOTKN);
	cr_expect_eq(ft_handle_error(NO_ERROR, NULL), ENOTKN);
	str = "|123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "123";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = ";|";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "; |";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "|123|;";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
	str = "|123| ;";
	cr_expect_eq(ft_verify_pipe(str), NO_ERROR);
}
