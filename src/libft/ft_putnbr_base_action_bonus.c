/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_action_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:34:20 by dakim             #+#    #+#             */
/*   Updated: 2020/07/10 19:59:11 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_action_ui(unsigned int value, int fd,
								unsigned int base, bool is_capital)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (value != 0)
	{
		if (value > base - 1)
			return_value += ft_putnbr_action_ul(value / base,
										fd, base, is_capital);
		if (0 <= (value % base) && (value % base) <= 9)
			c = (value % base) + '0';
		else if (10 <= (value % base))
		{
			if (is_capital)
				c = (value % base) + '7';
			else
				c = (value % base) + 'W';
		}
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}

int	ft_putnbr_action_ul(unsigned long value, int fd,
								unsigned long base, bool is_capital)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (value != 0)
	{
		if (value > base - 1)
			return_value += ft_putnbr_action_ul(value / base,
										fd, base, is_capital);
		if (0 <= (value % base) && (value % base) <= 9)
			c = (value % base) + '0';
		else if (10 <= (value % base))
		{
			if (is_capital)
				c = (value % base) + '7';
			else
				c = (value % base) + 'W';
		}
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}

int	ft_putnbr_action_ull(unsigned long long value, int fd,
								unsigned long long base, bool is_capital)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (value != 0)
	{
		if (value > base - 1)
			return_value += ft_putnbr_action_ul(value / base,
										fd, base, is_capital);
		if (0 <= (value % base) && (value % base) <= 9)
			c = (value % base) + '0';
		else if (10 <= (value % base))
		{
			if (is_capital)
				c = (value % base) + '7';
			else
				c = (value % base) + 'W';
		}
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}

int	ft_putnbr_action_uh(unsigned short value, int fd,
								unsigned short base, bool is_capital)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (value != 0)
	{
		if (value > base - 1)
			return_value += ft_putnbr_action_uh(value / base,
										fd, base, is_capital);
		if (0 <= (value % base) && (value % base) <= 9)
			c = (value % base) + '0';
		else if (10 <= (value % base))
		{
			if (is_capital)
				c = (value % base) + '7';
			else
				c = (value % base) + 'W';
		}
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}

int	ft_putnbr_action_uhh(unsigned char value, int fd,
								unsigned char base, bool is_capital)
{
	char	c;
	int		return_value;

	return_value = 0;
	if (value != 0)
	{
		if (value > base - 1)
			return_value += ft_putnbr_action_uhh(value / base,
										fd, base, is_capital);
		if (0 <= (value % base) && (value % base) <= 9)
			c = (value % base) + '0';
		else if (10 <= (value % base))
		{
			if (is_capital)
				c = (value % base) + '7';
			else
				c = (value % base) + 'W';
		}
		return_value += write(fd, &c, 1);
	}
	return (return_value);
}
