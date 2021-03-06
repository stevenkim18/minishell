/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:01:23 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 12:58:21 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = -1;
	while (++i < n)
	{
		*(str + i) = 0;
	}
	s = str;
}
