/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_cd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stevenkim <stevenkim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:39:09 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/24 21:34:35 by stevenkim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_path(const char *command)
{
	char	**argv;
	char	*path;
	int		idx;

	argv = ft_split(command, ' ');
	idx = 0;
	while (argv[idx])
		idx++;
	if (idx > 1)
		path = ft_strdup(argv[1]);
	else
		path = NULL;
	idx = -1;
	while (argv[++idx])
		free(argv[idx]);
	free(argv);
	return (path);
}

int		ft_handle_cd(const char *command, int *index)
{
	char	*path;

	path = ft_get_path(command);
    ft_return_end(command, index);
	chdir(path);
	free(path);
    return (NO_ERROR);
}