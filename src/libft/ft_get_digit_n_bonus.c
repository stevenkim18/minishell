/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digit_n_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 18:30:17 by dakim             #+#    #+#             */
/*   Updated: 2020/07/10 19:51:56 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digit_uhh(unsigned char n, unsigned char base)
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

int	ft_get_digit_uh(unsigned short n, unsigned short base)
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

int	ft_get_digit_ui(unsigned int n, unsigned int base)
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

int	ft_get_digit_ul(unsigned long n, unsigned long base)
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

int	ft_get_digit_ull(unsigned long long n, unsigned long long base)
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
