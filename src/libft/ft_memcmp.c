/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:17:44 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 15:18:34 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_str;
	unsigned char	*s2_str;
	size_t			i;

	i = -1;
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (++i < n)
		if (*(s1_str + i) != *(s2_str + i))
			break ;
	if (i == n)
		return (0);
	return (*(s1_str + i) - *(s2_str + i));
}
