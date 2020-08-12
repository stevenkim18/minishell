/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:54:43 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 09:00:50 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_str;
	unsigned char	*src_str;
	size_t			i;

	if (dest || src)
	{
		dest_str = (unsigned char *)dest;
		src_str = (unsigned char *)src;
		i = -1;
		if (src_str < dest_str)
			while (n-- > 0)
				*(dest_str + n) = *(src_str + n);
		else
			while (++i < n)
				*(dest_str + i) = *(src_str + i);
		return (dest);
	}
	return (NULL);
}
