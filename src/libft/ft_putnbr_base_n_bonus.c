/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_n_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 07:38:58 by dakim             #+#    #+#             */
/*   Updated: 2020/07/10 19:57:12 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_base_ui(unsigned int value, int fd,
							unsigned int base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ul(value, fd, base, is_capital)
			+ return_value);
}

int			ft_putnbr_base_ul(unsigned long value, int fd,
							unsigned long base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ul(value, fd, base, is_capital)
			+ return_value);
}

int			ft_putnbr_base_ull(unsigned long long value, int fd,
							unsigned long long base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ull(value, fd, base, is_capital)
			+ return_value);
}

int			ft_putnbr_base_uh(unsigned short value, int fd,
							unsigned short base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ull(value, fd, base, is_capital)
			+ return_value);
}

int			ft_putnbr_base_uhh(unsigned char value, int fd,
							unsigned char base, bool is_capital)
{
	int return_value;

	return_value = 0;
	if (1 < base)
		if (value == 0)
			return_value += write(fd, "0", 1);
	return (ft_putnbr_action_ull(value, fd, base, is_capital)
			+ return_value);
}
