/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunkim <seunkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:30:00 by seunkim           #+#    #+#             */
/*   Updated: 2020/08/10 17:35:08 by seunkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_pid;

int		gnl(char **line)
{
	write(1, "PINE APPLE >>", 13);
	return (get_next_line(1, line));
}

void		ft_sigint(int siginfo)
{
	exit(g_pid);
}

int main()
{
	int		ret;
	char	*command;

	command = NULL;
	// g_pid = fork();
	signal(SIGINT, ft_sigint);
	while ((ret = gnl(&command)) > 0)
	{
		printf("%s\n", command);
		// 파싱
		// 함수 실행
		free(command);
	}
	if (command)
		free(command);
}
