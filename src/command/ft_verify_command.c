/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:10:50 by dakim             #+#    #+#             */
/*   Updated: 2020/08/19 16:22:00 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int			ft_verify_pipe(const char *command)
{
	char	*pipe_location;
	int		index;

	index = 1;
	if ((pipe_location = ft_strnstr(command, PIPE_STR, ft_strlen((char*)command))))
	{
		while (*(pipe_location + index)
		&& ft_strnstr(pipe_location + index, SPACE_STR, ft_strlen(SPACE_STR)))
			++index;
		if (ft_strnstr(pipe_location + index, SEMICOLON_STR, ft_strlen(SEMICOLON_STR)))
		{
			ft_handle_error(ENOTKN, ENOTKN_S);
			return (ENOTKN);
		}
		else
			return (ft_verify_pipe(++pipe_location));
	}
	return (NO_ERROR);
}

int			ft_verify_semicolon(const char *command)
{
	char	*semicolon_location;
	int		index;

	index = 1;
	if ((semicolon_location = ft_strnstr(command, SEMICOLON_STR, ft_strlen((char*)command))))
	{
		while (*(semicolon_location + index)
		&& ft_strnstr(semicolon_location + index, SPACE_STR, ft_strlen(SPACE_STR)))
			++index;
		if (ft_strnstr(semicolon_location + index, PIPE_STR, ft_strlen(PIPE_STR)))
		{
			ft_handle_error(ENOTKN, ENOTKN_P);
			return (ENOTKN);
		}
		else
			return (ft_verify_semicolon(++semicolon_location));
	}
	return (NO_ERROR);
}

/*
int			ft_verify_command(const char *command)
{


}
*/
