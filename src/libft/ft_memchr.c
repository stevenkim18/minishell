/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:12:32 by dakim             #+#    #+#             */
/*   Updated: 2020/04/12 16:30:44 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_str;

	i = 0;
	s_str = (unsigned char *)s;
	while (i < n)
	{
		if (*(s_str + i) == (unsigned char)c)
			return ((s_str + i));
		++i;
	}
	return (NULL);
}
