/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_s_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:41:32 by dakim             #+#    #+#             */
/*   Updated: 2020/05/01 18:42:51 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_base_l(long value, int fd, long base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ul(value, fd, base, is_capital)
			+ return_value);
}
