/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:15:33 by dakim             #+#    #+#             */
/*   Updated: 2020/08/12 11:17:05 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_end_process(const int error_num, void *content)
{
	ft_putstr_fd("minishell: ", STDOUT);
	ft_putstr_fd(strerror(error_num), STDOUT);
	if (content)
		ft_putstr_fd(content, STDOUT);
	exit(1);
}
