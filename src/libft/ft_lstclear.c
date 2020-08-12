/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:54:31 by dakim             #+#    #+#             */
/*   Updated: 2020/07/16 15:56:16 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp_node;

	while (*lst)
	{
		tmp_node = NULL;
		tmp_node = *lst;
		*lst = (*lst)->next;
		del(tmp_node->content);
		free(tmp_node);
	}
}

t_list	*ft_lstclear_front_bonus(t_list **list)
{
	t_list		*tmp_list;

	tmp_list = *list;
	free(tmp_list);
	*list = (*list)->next;
	return (*list);
}
