/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:45:28 by dakim             #+#    #+#             */
/*   Updated: 2020/06/07 17:47:47 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew_bonus(void *content)
{
	t_list	*return_node;

	return_node = NULL;
	if (content)
	{
		if ((return_node = (t_list *)malloc(sizeof(t_list))))
		{
			return_node->next = NULL;
			return_node->content = content;
		}
	}
	return (return_node);
}
