/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:04:42 by dakim             #+#    #+#             */
/*   Updated: 2020/04/06 13:10:11 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list *return_node;

	return_node = NULL;
	if ((return_node = (t_list *)malloc(sizeof(t_list))))
	{
		return_node->next = NULL;
		return_node->content = content;
	}
	return (return_node);
}
