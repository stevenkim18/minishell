/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:56:08 by dakim             #+#    #+#             */
/*   Updated: 2020/04/07 18:31:51 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*return_str;

	if (!(return_str = malloc(nelem * elsize)))
		return (NULL);
	ft_memset(return_str, 0, nelem * elsize);
	return (return_str);
}
