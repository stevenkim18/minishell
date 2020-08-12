/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:37:30 by dakim             #+#    #+#             */
/*   Updated: 2020/04/12 10:29:09 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*next_node;
	void	*content;

	new_node = NULL;
	if (lst && (*f))
	{
		content = (*f)(lst->content);
		if (!(new_node = ft_lstnew(content)))
		{
			del(content);
			return (NULL);
		}
		if (lst->next)
		{
			if (!(next_node = ft_lstmap(lst->next, f, del)))
			{
				del(content);
				free(new_node);
				return (NULL);
			}
			new_node->next = next_node;
		}
	}
	return (new_node);
}
