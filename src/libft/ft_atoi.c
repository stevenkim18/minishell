/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 12:44:44 by dakim             #+#    #+#             */
/*   Updated: 2020/07/27 16:27:23 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int		ft_check_range(unsigned long long number, int sign)
{
	if (number > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (number > LLONG_MAX && sign == 1)
		return (-1);
	return (number * sign);
}

int		ft_atoi(char *str)
{
	unsigned long long	number_value;
	int					sign_value;
	int					i;

	i = 0;
	number_value = 0;
	sign_value = 1;
	while ((*(str + i) == '\t' || *(str + i) == '\n'
		|| *(str + i) == '\v' || *(str + i) == '\f'
		|| *(str + i) == '\r' || *(str + i) == ' ') && *(str + i))
		i++;
	if (*(str + i) == '-')
		sign_value = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (('0' <= *(str + i) && *(str + i) <= '9') && *(str + i))
	{
		number_value = number_value * 10 + (*(str + i) - '0');
		i++;
	}
	return (ft_check_range(number_value, sign_value));
}
