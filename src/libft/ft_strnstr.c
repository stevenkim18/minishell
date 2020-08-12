/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:02:10 by dakim             #+#    #+#             */
/*   Updated: 2020/04/13 07:37:30 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*(little))
		return ((char*)big);
	while (i < len && *(big + i))
	{
		j = 0;
		while (*(little + j) == *(big + i + j) && i + j < len)
		{
			if (!*(little + j + 1))
				return ((char*)(big + i));
			++j;
		}
		++i;
	}
	return (NULL);
}
