/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_h_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:24:40 by dakim             #+#    #+#             */
/*   Updated: 2020/07/10 20:05:35 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_action(unsigned short n, int fd)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (n != 0)
	{
		if (n > 9)
			return_value += ft_putnbr_action(n / 10, fd);
		c = (n % 10) + '0';
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}

int			ft_putnbr_fd_only_number_h(short n, int fd)
{
	int return_value;

	return_value = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		return_value += write(fd, "0", 1);
	return (ft_putnbr_action((unsigned short)n, fd) + return_value);
}

int			ft_putnbr_fd_unsigned_int_h(unsigned short n, int fd)
{
	int return_value;

	return_value = 0;
	if (n == 0)
		return_value += write(fd, "0", 1);
	return (ft_putnbr_action(n, fd) + return_value);
}
