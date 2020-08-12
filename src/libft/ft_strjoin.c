/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:08:32 by dakim             #+#    #+#             */
/*   Updated: 2020/04/08 08:09:04 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_str;
	char	*s2_str;
	char	*return_str;
	int		i;
	int		j;

	return_str = NULL;
	if (s1 && s2)
	{
		s1_str = (char *)s1;
		s2_str = (char *)s2;
		if ((return_str = malloc(sizeof(char) *
					(ft_strlen(s1_str) + ft_strlen(s2_str) + 1))))
		{
			i = 0;
			j = 0;
			while (*(s1_str + j))
				*(return_str + (i++)) = *(s1_str + (j++));
			j = 0;
			while (*(s2_str + j))
				*(return_str + (i++)) = *(s2_str + (j++));
			*(return_str + i) = 0;
		}
	}
	return (return_str);
}
