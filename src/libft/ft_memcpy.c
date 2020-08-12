/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:01:39 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 08:32:12 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_str;
	char	*src_str;
	size_t	i;

	if (dest || src)
	{
		dest_str = (char *)dest;
		src_str = (char *)src;
		i = -1;
		while (++i < n)
		{
			*(dest_str + i) = *(src_str + i);
		}
		dest = dest_str;
		return (dest);
	}
	return (NULL);
}
