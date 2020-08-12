/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 21:48:58 by dakim             #+#    #+#             */
/*   Updated: 2020/04/27 22:17:55 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_char(char *delimiter, char c)
{
	int i;

	i = -1;
	while (*(delimiter + ++i))
		if (*(delimiter + i) == c)
			return (1);
	return (0);
}
