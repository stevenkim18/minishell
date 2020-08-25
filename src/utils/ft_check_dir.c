/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:03:38 by dakim             #+#    #+#             */
/*   Updated: 2020/08/25 16:06:44 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				ft_check_dir(const char *str)
{
	if (ft_strnstr(str, "/", ft_strlen((char*)str)))
		return (0);
	return (-1);
}
