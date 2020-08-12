/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 03:00:11 by dakim             #+#    #+#             */
/*   Updated: 2020/04/29 03:00:55 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd_int(char *s, int fd)
{
	int i;
	int return_value;

	i = -1;
	return_value = 0;
	if (s)
		while (++i < ft_strlen(s))
			return_value += write(fd, (s + i), 1);
	return (return_value);
}
