/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_route_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:27:38 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 16:01:00 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_trim_str(const char *str)
{
	char	*return_str;

	if (!(return_str = ft_strtrim(str, SPACE_STR)))
		ft_handle_error(ENOMEM, NULL);
	return (return_str);
}

void		ft_route_command(const char *str)
{
	if (str)
	{
		if (ft_strnstr(str, ECHO_STR, ft_strlen(ECHO_STR)))
		{

		}
		else if (ft_strnstr(str, CD_STR, ft_strlen(CD_STR)))
		{

		}
		else if (ft_strnstr(str, PWD_STR, ft_strlen(PWD_STR)))
		{

		}
		else if (ft_strnstr(str, EXPORT_STR, ft_strlen(EXPORT_STR)))
		{

		}
		else if (ft_strnstr(str, ENV_STR, ft_strlen(ENV_STR)))
		{

		}
		else if (ft_strnstr(str, UNSET_STR, ft_strlen(UNSET_STR)))
		{

		}
		else if (ft_strnstr(str, EXIT_STR, ft_strlen(EXIT_STR)))
		{

		}
		else
		{

		}
	}
	else
		ft_handle_error(ENOMEM, NULL);
}
