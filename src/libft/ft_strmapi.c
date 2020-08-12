/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:24:08 by dakim             #+#    #+#             */
/*   Updated: 2020/04/08 08:19:15 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*return_str;
	int		len;
	int		i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	return_str = NULL;
	if ((return_str = ft_calloc(sizeof(char), (len + 1))))
	{
		i = -1;
		while (++i < len)
			*(return_str + i) = f(i, *(s + i));
	}
	return (return_str);
}
