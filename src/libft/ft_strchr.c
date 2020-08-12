/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:03:27 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 15:26:02 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		len;
	char	*str;
	int		i;

	str = (char *)s;
	len = ft_strlen((char *)str);
	i = -1;
	while (++i < len + 1)
	{
		if (*(str + i) == c)
		{
			return (str + i);
		}
	}
	return (NULL);
}
