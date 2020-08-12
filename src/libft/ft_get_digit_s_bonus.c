/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit_s_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 20:07:49 by dakim             #+#    #+#             */
/*   Updated: 2020/07/09 16:09:59 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digit_i(int n, int base)
{
	int count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}

int	ft_get_digit_h(short n, short base)
{
	int count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}

int	ft_get_digit_hh(char n, char base)
{
	int count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}

int	ft_get_digit_l(long n, long base)
{
	int count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}

int	ft_get_digit_ll(long long n, long long base)
{
	int count;

	count = 0;
	if (!n)
		++count;
	while (n)
	{
		++count;
		n /= base;
	}
	return (count);
}
