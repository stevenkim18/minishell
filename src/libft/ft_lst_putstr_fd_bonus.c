/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_fd_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <daeungkim93@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 09:08:11 by dakim             #+#    #+#             */
/*   Updated: 2020/04/08 09:08:53 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lst_putstr_fd_action(t_list *lst, int fd)
{
	if (lst)
	{
		write(fd, " ", 1);
		ft_putstr_fd((char*)lst->content, fd);
		ft_lst_putstr_fd_action(lst->next, fd);
	}
}

void			ft_lst_putstr_fd(t_list *lst, int fd)
{
	if (lst)
	{
		write(fd, "List =", 6);
		ft_lst_putstr_fd_action(lst, fd);
		write(fd, "\n", 1);
	}
}
