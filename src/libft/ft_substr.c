/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 00:15:08 by dakim             #+#    #+#             */
/*   Updated: 2020/04/12 11:09:06 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*return_str;

	i = 0;
	return_str = NULL;
	if (s)
	{
		if (!(return_str = ft_calloc(sizeof(char), len + 1)))
			return (NULL);
		if (!((size_t)ft_strlen((char*)s) < start))
			while (*(s + i + start) && i < len)
			{
				*(return_str + i) = *(s + i + start);
				++i;
			}
	}
	return (return_str);
}
