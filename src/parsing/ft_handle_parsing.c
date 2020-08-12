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
		ft_handle_error(ENOMEM, EXIT_ERROR, NULL, NULL);
	return (return_str);
}

int			ft_handle_parsing(const char *str)
{
	if (ft_strnstr(str, ECHO_STR, ft_strlen(ECHO_STR)))
		return (ECHO_INT);
	else if (ft_strnstr(str, CD_STR, ft_strlen(CD_STR)))
		return (CD_INT);
	else if (ft_strnstr(str, PWD_STR, ft_strlen(PWD_STR)))
		return (PWD_INT);
	else if (ft_strnstr(str, EXPORT_STR, ft_strlen(EXPORT_STR)))
		return (EXPORT_INT);
	else if (ft_strnstr(str, ENV_STR, ft_strlen(ENV_STR)))
		return (ENV_INT);
	else if (ft_strnstr(str, UNSET_STR, ft_strlen(UNSET_STR)))
		return (UNSET_INT);
	else if (ft_strnstr(str, EXIT_STR, ft_strlen(EXIT_STR)))
		return (EXIT_INT);
	else
		return (INITIAL_INT);
}
