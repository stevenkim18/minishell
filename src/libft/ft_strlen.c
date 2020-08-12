/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:01:59 by dakim             #+#    #+#             */
/*   Updated: 2020/07/15 17:16:19 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		++i;
	}
	return (i);
}

int	ft_strlen_w(wchar_t *str)
{
	int i;

	i = 0;
	while (*(str + i))
	{
		++i;
	}
	return (i);
}
