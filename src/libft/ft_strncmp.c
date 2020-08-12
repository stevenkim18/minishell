/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:18:53 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 17:52:43 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_str;
	unsigned char	*s2_str;
	size_t			i;

	i = -1;
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (++i < n - 1 && *(s1_str + i) && *(s2_str + i))
	{
		if (*(s1_str + i) != *(s2_str + i))
			break ;
	}
	if (n)
		return (*(s1_str + i) - *(s2_str + i));
	return (0);
}
