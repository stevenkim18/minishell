/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:59:48 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 08:21:14 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = -1;
	if (!dst || !src)
		return (0);
	if (size)
	{
		while (++i < (int)(size - 1) && *(src + i))
			*(dst + i) = *(src + i);
		*(dst + i) = 0;
	}
	return ((size_t)ft_strlen((char*)src));
}
