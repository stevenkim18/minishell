/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:01:04 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 08:35:18 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;
	size_t			i;

	dest_str = (unsigned char *)dest;
	src_str = (unsigned char *)src;
	i = -1;
	while (++i < n)
	{
		*(dest_str + i) = *(src_str + i);
		if (*(src_str + i) == (unsigned char)c)
			return (dest_str + i + 1);
	}
	return (NULL);
}
