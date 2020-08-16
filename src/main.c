/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakim <dakim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:04:27 by dakim             #+#    #+#             */
/*   Updated: 2020/08/16 11:59:04 by dakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_leak_test(void)
{
	pid_t pid;

	char *str = NULL;
	pid = fork();
	int parent;
	wait(&parent);
	if (pid == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		*str = '5';
		*(str + 1) = 0;
		printf("child = %s\n", str);

		pid_t pid1;
		int child;

		pid1 = fork();
		wait(&child);
		if (pid1 == 0)
		{
			printf("grand child = %s\n", str);
			exit(0);
		}
		exit(0);
	}
	printf("parent = %s\n", str);
}

int				main(void)
{
	// ft_open_pipe();
	// ft_handle_command();
	// ft_close_pipe();

	ft_leak_test();
	while (1)
		;

	return (0);
}
