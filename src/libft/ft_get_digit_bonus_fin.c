/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit_bonus_fin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 16:08:36 by dakim             #+#    #+#             */
/*   Updated: 2020/07/27 16:19:50 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_dight_zu(size_t n, size_t base)
{
	int	count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}
