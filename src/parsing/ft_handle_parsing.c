/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 15:38:51 by dakim             #+#    #+#             */
/*   Updated: 2020/08/12 09:5 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_trim_str(const char *str)
{
	char	*return_str;

	if (!(return_str = ft_strtrim(str, SPACE_STR)))
		ft_end_process();
	return (return_str);
}

/*
int			ft_handle_parsing(const char *str)
{

}
*/
