/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 17:37:00 by dakim             #+#    #+#             */
/*   Updated: 2020/06/07 17:39:19 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstadd_back_bonus(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		if (ft_lstlast(*lst))
			ft_lstlast(*lst)->next = new;
		else
			(*lst) = new;
		return (1);
	}
	return (0);
}
