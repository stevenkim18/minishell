/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:49:07 by dakim             #+#    #+#             */
/*   Updated: 2020/04/08 08:24:47 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int i;

	i = -1;
	if (s)
	{
		while (++i < ft_strlen(s))
			write(fd, (s + i), 1);
		write(fd, "\n", 1);
	}
}
