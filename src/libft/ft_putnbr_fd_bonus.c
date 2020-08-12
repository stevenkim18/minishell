/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:50:49 by dakim             #+#    #+#             */
/*   Updated: 2020/04/29 01:12:18 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_action(unsigned int n, int fd)
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

int			ft_putnbr_fd_return_int(int n, int fd)
{
	int return_value;

	return_value = 0;
	if (n < 0)
	{
		n *= -1;
		return_value += write(fd, "-", 1);
	}
	else if (n == 0)
		return_value += write(fd, "0", 1);
	return (ft_putnbr_action((unsigned int)n, fd) + return_value);
}

int			ft_putnbr_fd_only_number(int n, int fd)
{
	int return_value;

	return_value = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		return_value += write(fd, "0", 1);
	return (ft_putnbr_action((unsigned int)n, fd) + return_value);
}

int			ft_putnbr_fd_unsigned_int(unsigned int n, int fd)
{
	int return_value;

	return_value = 0;
	if (n == 0)
		return_value += write(fd, "0", 1);
	return (ft_putnbr_action(n, fd) + return_value);
}
