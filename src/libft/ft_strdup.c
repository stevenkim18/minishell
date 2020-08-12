/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:57:34 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 13:28:17 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*return_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(s + i))
		++i;
	if ((return_str = (char *)malloc(sizeof(char) * (i + 1))))
	{
		while (j < i)
		{
			*(return_str + j) = *(s + j);
			++j;
		}
		*(return_str + j) = 0;
	}
	else
		free(return_str);
	return (return_str);
}
