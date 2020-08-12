/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:15:33 by dakim             #+#    #+#             */
/*   Updated: 2020/08/12 12:39:23 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_handle_error(const int error_num, const int exit_num,
							void *custom_error, void *content)
{
	ft_putstr_fd("minishell: ", STDOUT);
	if (0 < error_num)
		ft_putstr_fd(strerror(error_num), STDOUT);
	if (custom_error)
		ft_putstr_fd(custom_error, STDOUT);
	if (content)
		ft_putstr_fd(content, STDOUT);
	if (exit_num != -1)
		exit(exit_num);
}
