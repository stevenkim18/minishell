/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:50:49 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 11:52:47 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_action(unsigned int n, int fd)
{
	char c;

	if (n != 0)
	{
		if (n > 9)
			ft_putnbr_action(n / 10, fd);
		c = (n % 10) + '0';
		write(fd, &c, 1);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	else if (n == 0)
		write(fd, "0", 1);
	ft_putnbr_action((unsigned int)n, fd);
}
