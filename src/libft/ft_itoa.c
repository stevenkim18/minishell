/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:52:22 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 13:05:15 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_get_digit(int n)
{
	int count;

	count = 0;
	while (n)
	{
		++count;
		n /= 10;
	}
	return (count);
}

static void	ft_putnbr(unsigned int n, char *str, int index)
{
	if (n > 9)
		ft_putnbr(n / 10, str, index - 1);
	*(str + index) = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	char	*return_str;
	int		len;

	return_str = NULL;
	len = ft_get_digit(n);
	if ((return_str = malloc(sizeof(char) * (len + 2))))
	{
		*(return_str + (len + 1)) = 0;
		if (n < 0)
		{
			*return_str = '-';
			n *= -1;
		}
		else if (0 < n)
		{
			*(return_str + len) = 0;
			--len;
		}
		ft_putnbr((unsigned int)n, return_str, len);
	}
	return (return_str);
}
